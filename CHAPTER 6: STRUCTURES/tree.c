#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ------------------------------------ Definitions ------------------------------------------------------------

#define MAXWORD 20 // Taille maximale d'un mot
#define BUFSIZE 100

int bufp = 0;      // Position dans le buffer
char buf[BUFSIZE]; // Buffer utilisé pour stocker les caractères

// ---------------------------------- Prototypes ----------------------------------------------------------------

struct tnode *addtree(struct tnode *p, char *w);
void treeprint(struct tnode *p);

char *strsave(char *s);
int getword(char *w, int lim);

int getch(void);
void ungetch(int c);

// ---------------------    Structure pour représenter un nœud dans l'arbre -----------------------------------
struct tnode
{
    char *word;          // Pointeur vers le mot
    int count;           // Nombre d'occurrences du mot
    struct tnode *left;  // Fils gauche (mots plus petits)
    struct tnode *right; // Fils droit (mots plus grands)
};

// ------------------------------------------------------------------------------------------------------------

int main(void)
{
    struct tnode *root = NULL; // Initialisation de l'arbre
    char word[MAXWORD];        // Buffer pour stocker les mots

    // Lire chaque mot et l'ajouter à l'arbre
    while (getword(word, MAXWORD) != EOF)
    {

        if (isalpha(word[0]))
        { // Si le premier caractère est une lettre
            root = addtree(root, word);
        }
    }

    printf("\n\n");
    printf("EOF\n");

    treeprint(root); // Afficher l'arbre en ordre alphabétique
    return 0;
}

//  ----------------------  Fonction pour ajouter un mot dans l'arbre ------------------------------------------

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    // Si le nœud est vide, créer un nouveau nœud
    if (p == NULL)
    {
        p = (struct tnode *)malloc(sizeof(struct tnode));
        if (p == NULL)
        {
            fprintf(stderr, "Erreur d'allocation mémoire\n");
            exit(EXIT_FAILURE);
        }
        p->word = strsave(w);      // Sauvegarde du mot
        p->count = 1;              // Initialisation du compteur d'occurrences
        p->left = p->right = NULL; // Fils gauche et droit à NULL
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {
        p->count++; // Le mot existe déjà, incrémenter le compteur
    }
    else if (cond < 0)
    {
        p->left = addtree(p->left, w); // Le mot est plus petit, aller à gauche
    }
    else
    {
        p->right = addtree(p->right, w); // Le mot est plus grand, aller à droite
    }

    return p;
}

// ---------------------------------------------------- Fonction pour sauvegarder une chaîne de caractères ---------------------------------

char *strsave(char *s)
{
    char *p = malloc(strlen(s) + 1); // Allouer la mémoire
    if (p != NULL)
    {
        strcpy(p, s); // Copier la chaîne dans la nouvelle zone de mémoire
    }
    else
    {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

// -------------------------------------------------------  Fonction pour lire un mot depuis l'entrée standard -----------------------------------
int getword(char *w, int lim)
{
    int c;

    // Ignorer les espaces blancs
    while (isspace(c = getch()))
        ;

    if(c == EOF)
    {
        return EOF;
    }

    // Si ce n'est pas une lettre, retourner le caractère
    if (c != EOF && !isalpha(c))
    {
        *w = '\0'; // Terminer la chaîne
        return c;
    }

    // Sinon, lire le mot
    if (c != EOF)
    {
        *w++ = c;
    }

    // Lire le reste du mot tant qu'il est alphanumérique
    while (--lim > 0)
    {
        c = getchar();
        if (!isalnum(c))
        {
            ungetch(c); // Remettre le caractère dans l'entrée si non alphanumérique
            break;
        }
        *w++ = c;
    }
    *w = '\0'; // Terminer la chaîne de caractères

    return w[0]; // Retourner le premier caractère du mot
}

// Fonction pour imprimer l'arbre en ordre alphabétique (in-order traversal)
void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);                    // Afficher le sous-arbre gauche
        printf("%4d %s\n", p->count, p->word); // Afficher le mot et son compteur
        treeprint(p->right);                   // Afficher le sous-arbre droit
    }
}

// ---------------------------- Lire un caractère depuis le buffer ou l'entrée standard --------------------------------------------------
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// -----------------------------    Remettre un caractère dans le buffer -----------------------------------------------------------------
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: trop de caractères\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

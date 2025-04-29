#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXWORD 100
#define BUFSIZE 100
#define LETTER 'a'

int bufp = 0;
char buf[BUFSIZE];

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar(); // Remplace getchar() par EOF si on veut arrêter la lecture
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

int getword(char *w, int lim)
{
    int c = getch();

    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }
    *w++ = c;

    while (--lim > 0)
    {
        c = getch();
        if (!isalnum(c))
        {
            ungetch(c);
            break;
        }
        *w++ = c;
    }
    *w = '\0';

    return LETTER;
}

char *strsave(char *s) /* sauvegarde de la chaîne s quelque part */
{
    char *p;
    if ((p = malloc(strlen(s) + 1)) != NULL)
        strcpy(p, s);
    return (p);
}

typedef struct linkedList
{
    char *name;
    struct linkedList *next;
} linkedList, *POINTEUR_LIST;

typedef struct tnode
{
    struct linkedList *list;
    struct tnode *left;
    struct tnode *right;
} NOEUD_ARBRE, *POINTEUR_ARBRE;

POINTEUR_ARBRE tree(POINTEUR_ARBRE p, char *w)
{
    int cond;

    if (p == NULL)
    {
        p = (POINTEUR_ARBRE)malloc(sizeof(NOEUD_ARBRE));
        POINTEUR_LIST l = (POINTEUR_LIST)malloc(sizeof(linkedList));
        l->name = strsave(w);
        l->next = NULL;
        p->list = l;
        p->left = p->right = NULL;
    }
    else if (strncmp(w, p->list->name, 7) == 0)
    {
        // Vérification pour éviter les doublons
        POINTEUR_LIST current = p->list;

        // Parcourir la liste pour chercher un doublon
        while (current != NULL)
        {
            if (strcmp(current->name, w) == 0)
            {
                // Le mot existe déjà, ne pas l'ajouter
                return p;
            }
            current = current->next;
        }

        // Le mot n'existe pas dans la liste, on peut l'ajouter
        POINTEUR_LIST list = p->list;
        while (list->next)
        {
            list = list->next;
        }

        POINTEUR_LIST new_l = (POINTEUR_LIST)malloc(sizeof(linkedList));
        if (new_l == NULL)
        {
            fprintf(stderr, "Erreur: impossible d'allouer la mémoire\n");
            return p;
        }
        new_l->name = strsave(w);
        new_l->next = NULL;
        list->next = new_l;
    }
    else if ((cond = strcmp(w, p->list->name)) != 0)
    {
        if (cond < 0)
        {
            p->left = tree(p->left, w);
        }
        else
        {
            p->right = tree(p->right, w);
        }
    }

    return (p);
}

void print_tree(POINTEUR_ARBRE p)
{
    if (p != NULL)
    {
        print_tree(p->left);

        POINTEUR_LIST list = p->list;
        printf("Node:\n");
        while (list)
        {
            printf("  - %s\n", list->name);
            list = list->next;
        }

        print_tree(p->right);
    }
}

int main()
{
    char word[MAXWORD];

    POINTEUR_ARBRE root = NULL;
    int result;

    while ((result = getword(word, MAXWORD)) != EOF)
    {
        if (result == LETTER)
        {
            root = tree(root, word);
        }
    }

    print_tree(root);

    // Libération propre
    // ree_tree(root);

    return 0;
}
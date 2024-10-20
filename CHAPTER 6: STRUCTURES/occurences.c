#include <stdio.h>
#include <string.h> // Ajouté pour la fonction strcmp

#define MAXWORD 20
#define BUFSIZE 100
#define NKEYS (sizeof(keytab) / sizeof(struct key)) // Calcul du nombre de clés

// Types de caractères pour la classification
#define LETTER 1
#define DIGIT 2

int bufp = 0; // Position dans le buffer
char buf[BUFSIZE]; // Buffer utilisé pour stocker les caractères

// Structure de la table des mots-clés
struct key {
    char *keyword;
    int keycount;
} keytab[] = {
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"continue", 0},
    {"default", 0},
    {"unsigned", 0},
    {"while", 0}
};

// -------------------------------- Prototypes des fonctions --------------------------------------------------------------
int getword(char *word, int lim);
int binary(char *word, struct key tab[], int n);
int getch(void);
void ungetch(int c);
int type(int c); // Déclare la fonction type


//  -------------------------------------- Fonction principale ----------------------------------------------------------------
int main(void) {
    int n, t;
    char word[MAXWORD];

    // Lire les mots et mettre à jour la table des mots-clés
    while ((t = getword(word, MAXWORD)) != EOF) {
        if (t == LETTER) { // Si le mot est une lettre
            if ((n = binary(word, keytab, NKEYS)) >= 0) {
                keytab[n].keycount++; // Incrémenter le compteur si le mot-clé est trouvé
            }
        }
    }

    // Afficher les résultats
    for (n = 0; n < NKEYS; n++) {
        if (keytab[n].keycount > 0) {
            printf("%4d %s\n", keytab[n].keycount, keytab[n].keyword);
        }
    }

    return 0;
}

//  ----------------------------------- Fonction de recherche binaire dans la table des mots-clés -----------------------
int binary(char *word, struct key tab[], int n) {
    int low = 0, high = n - 1, mid, cond;

    while (low <= high) {
        mid = (low + high) / 2;
        cond = strcmp(word, tab[mid].keyword);
        if (cond < 0) {
            high = mid - 1;
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return mid; // Mot trouvé
        }
    }

    return -1; // Mot non trouvé
}

//  -----------------------------   Fonction pour lire un mot à partir de l'entrée --------------------------------
int getword(char *w, int lim) {
    int c, t;
    
    // Lire le premier caractère
    c = *w++ = getch();
    t = type(c);

    // Si ce n'est pas une lettre, retourner le caractère
    if (t != LETTER) {
        *w = '\0'; // Terminer le mot
        return c;
    }

    // Lire les autres caractères du mot
    while (--lim > 0) {
        t = type(c = getch());
        if (t != LETTER && t != DIGIT) {
            ungetch(c); // Remettre le caractère dans le buffer si ce n'est plus une lettre ou un chiffre
            break;
        }
        *w++ = c; // Ajouter le caractère au mot
    }

    *w = '\0'; // Terminer la chaîne de caractères
    return LETTER; // Retourner le type de caractère
}

// -------------------------------------    Fonction pour classer un caractère comme lettre, chiffre ou autre -------------------------
int type(int c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return LETTER;
    } else if (c >= '0' && c <= '9') {
        return DIGIT;
    } else {
        return c; // Retourner le caractère lui-même si ce n'est ni une lettre ni un chiffre
    }
}

// ---------------------------- Lire un caractère depuis le buffer ou l'entrée standard --------------------------------------------------
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// -----------------------------    Remettre un caractère dans le buffer -----------------------------------------------------------------
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: trop de caractères\n");
    } else {
        buf[bufp++] = c;
    }
}

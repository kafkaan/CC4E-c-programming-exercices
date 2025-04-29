#include <stdio.h>
#include <ctype.h>

#define LETTER 'a'
#define MAXWORD 100
#define BUFSIZE 100

int getword(char *w, int lim);
int getch(void);
void ungetch(int c);
void ungets(char s[]);

int bufp = 0;
char buf[BUFSIZE];

int main()
{
    char word[MAXWORD];
    int result;
    
    printf("Entrez du texte (CTRL+D pour terminer):\n");
    
    // Lire les mots jusqu'à EOF
    while ((result = getword(word, MAXWORD)) != EOF) {
        if (result == LETTER) {
            printf("Mot trouvé: \"%s\"\n", word);
        } else if (isprint(result)) {
            printf("Caractère trouvé: '%c'\n", result);
        } else {
            printf("Caractère non imprimable trouvé (code %d)\n", result);
        }
    }
    
    printf("\nFin du test.\n");
    return 0;
}


int getword(char *w, int lim)
{
    int c = getch(); // Lire le premier caractère
    if (!isalpha(c))
    {              // Vérifier si c'est une lettre
        *w = '\0'; // Si non, terminer la chaîne et retourner c
        return c;
    }
    *w++ = c; // Si c'est une lettre, ajouter à w

    while (--lim > 0)
    {
        c = getch(); // Lire les caractères suivants
        if (!isalnum(c))
        {               // Vérifier si c'est un chiffre ou une lettre
            ungetch(c); // Si non, remettre le caractère
            break;
        }
        *w++ = c; // Si c'est valide, ajouter à w
    }
    *w = '\0'; // Terminer la chaîne avec un '\0'
    return LETTER;
}


int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();  // Remplace getchar() par EOF si on veut arrêter la lecture
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

// Ungets entire string to buffer
void ungets(char s[])
{
    char *t = s;

    while(*t)
    {
        t++;
    }

    while(t >s)
    {
        ungetch(*--t);
    }
}


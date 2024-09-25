#include <stdio.h>
#include <ctype.h>
#include <time.h>

#define LETTER 'a'
#define DIGIT '0'
#define MAXWORD 1000
#define BUFSIZE 10000

int getword(char *w, int lim);
int getch(void);
void ungetch(int c);

int bufp = 0;
char buf[BUFSIZE];

// Simuler une entrée constante pour éviter la dépendance à la frappe de l'utilisateur
const char *input = "This is a test input to measure the performance of getword function. 12345 abcdef!";
int input_pos = 0; // Position actuelle dans le flux d'entrée simulé

int main(void)
{
    char word[MAXWORD];
    clock_t start, end;
    double cpu_time_used;

    // Mesurer le temps avant l'exécution de getword
    start = clock();

    while (getword(word, MAXWORD) != EOF)
    {
        printf("Word: %s\n", word);
    }

    // Mesurer le temps après l'exécution de getword
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Temps d'exécution : %f secondes\n", cpu_time_used);

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

// --------------------------- Simuler un flux d'entrée -------------

int getch(void)
{
    // Simuler la lecture d'un caractère depuis une chaîne prédéfinie
    return (input[input_pos] != '\0') ? input[input_pos++] : EOF;
}

void ungetch(int c)
{
    if (input_pos > 0)
    {
        input_pos--; // Reculer dans la chaîne simulée pour "remettre" le caractère
    }
}

// ###########################################################3
int type(int c) /* return type of ASCII character */
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        return (LETTER);

    else if (c >= '0' && c <= '9')
        return (DIGIT);
    else
        return (c);
}

getwordv2(char *w, int lim) /* get next word from input */
{
    int c, t;
    if (type(c = *w++ = getch()) != LETTER)
    {
        *w = '\0';
        return (c);
    }

    while (--lim > 0)
    {
        t = type(c = *w++ = getch());
        if (t != LETTER && t != DIGIT)
        {
            ungetch(c);
            break;
        }
    }
    *(w - 1) = '\0';
    return (LETTER);
}
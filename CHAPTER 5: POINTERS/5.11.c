/*
    * 5.11
    * Modify sort to handle a -r flag, which indicates sorting in reverse (decreasing) order.
    * Of course -r must work with -n.

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LINES 100   /* max number of lines to be sorted */
#define MAXLEN 1000 /* Longueur maximale d'une ligne */
#define MAXSTORE 10000

char lineStore[MAXSTORE];

void sort(char *v[], int n, int (*comp)(), int (*exch)());
int readlines(char *lineptr[], int maxlines);
int get_line(char *s, int lim);
void writelines(char *lineptr[], int nlines);
int numcmp(char *, char *);
int mystrcmp(char *, char *);
int swap(char **, char **);
double myAtof(char s[]);

void main(int argc, char *argv[]) /* sort input lines */
{
    char *lineptr[LINES];     /* pointers to text lines */
    int nlines;               /* number of input lines read */
    int mystrcmp(), numcmp(); /* comparison functions */
    int swap();               /* exchange function */
    int numeric = 0;          /* 1 if numeric sort */
    int reverse = 0;          /* 1 if reverse sort */

    while (argc > 1 && *argv[1] == '-')
    {
        if (strcmp((*++argv), "-n") == 0)
        {
            printf("NUMERIC \n");
            numeric = 1;
        }
        else if (strcmp((*argv), "-r") == 0)
        {
            printf("reverse\n");
            reverse = 1;
        }
        argc--;
    }

    if ((nlines = readlines(lineptr, LINES)) >= 0)
    {
        if (numeric && reverse)
        {
            printf("numeric and reverse\n");
            sort(lineptr, nlines, numcmp, swap);
            reverseLines(lineptr, nlines);
        }
        else if (numeric)
        {
            printf("numeric\n");
            sort(lineptr, nlines, numcmp, swap);
        }
        else if (reverse)
        {
            printf("reverse\n");
            sort(lineptr, nlines, mystrcmp, swap);
            reverseLines(lineptr, nlines);
        }
        else
            sort(lineptr, nlines, mystrcmp, swap);
        writelines(lineptr, nlines);
    }
    else
        printf("input too big to sort\n");
}

void sort(char *v[], int n, int (*comp)(), int (*exch)()) /* sort strings v[0]...v[n-1] */
{
    int gap, i, j;

    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0; j -= gap)
            {
                if ((*comp)(v[j], v[j + gap]) <= 0)
                    break;
                (*exch)(&v[j], &v[j + gap]);
            }
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines = 0;

    char *p, line[MAXLEN];

    p = lineStore;
    char *lineStop = lineStore + MAXSTORE;

    while ((len = get_line(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines)
        {
            return -1; /* Trop de lignes */
        }
        else if (lineStore + len < lineStop)
        {
            line[len - 1] = '\0'; /* Retirer le retour à la ligne */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}

int get_line(char *s, int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        *s++ = c;
    }
    if (c == '\n')
    {
        *s++ = c;
        ++i;
    }
    *s = '\0';
    return i;
}

void writelines(char *lineptr[], int nlines)
{
    for (int i = 0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
    }
}

//- ------------------------------------------------------
int numcmp(char *s1, char *s2) /* compare s1 and s2 numerically */
{
    double v1, v2;

    v1 = myAtof(s1);
    v2 = myAtof(s2);
    if (v1 < v2)
        return (-1);
    else if (v1 > v2)
        return (1);
    else
        return (0);
}

int mystrcmp(char *s, char *t) /* return <0 if s<t, 0 if s==t, >0 if s>t */
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return (0);
    return (*s - *t);
}

// -------------------------------------------------------
double myAtof(char s[])
{                      // Déclare la fonction myAtof qui prend une chaîne de caractères et renvoie un double
    double val, power; // Déclare deux variables de type double
    int i, sign;       // Déclare deux variables de type int

    int e_sign = 1;
    int exp = 0;

    for (i = 0; s[i] == ' ' || s[i] == '\\n' || s[i] == '\\t'; i++) // Boucle qui saute les espaces blancs en début de chaîne
        ;                                                           // Ne fait rien dans le corps de la boucle

    sign = 1; // Initialise le signe à 1 (pour un nombre positif)

    if (s[i] == '+' || s[i] == '-')      // Si le caractère courant est '+' ou '-', il détermine le signe du nombre
        sign = (s[i++] == '+') ? 1 : -1; // Si le caractère est '+', le signe reste 1, sinon il devient -1

    for (val = 0; s[i] >= '0' && s[i] <= '9'; i++) // Boucle qui parcourt les chiffres du nombre
        val = 10 * val + s[i] - '0';               // Convertit chaque chiffre en int et l'ajoute à val

    if (s[i] == '.') // Si le caractère courant est un point, il passe au caractère suivant
        i++;

    for (power = 1; s[i] >= '0' && s[i] <= '9'; i++)
    {                                // Boucle qui parcourt les chiffres après le point
        val = 10 * val + s[i] - '0'; // Convertit chaque chiffre en int et l'ajoute à val
        power *= 10;                 // Augmente la puissance de 10 à chaque itération
    }

    if (s[i] == 'E' || s[i] == 'e')
    {
        i++;
    }

    else if (s[i] == '-' || s[i] == '+')
    {
        e_sign = s[i];
    }

    for (exp = 0; isdigit(s[i]); i++)
    {
        exp = 10 * exp + (s[i] - '0');
    }

    if (e_sign == '-')
        return sign * (val / power) / powerExp(10, exp);
    else

        return sign * (val / power) * powerExp(10, exp);
}

int powerExp(int base, int exp)
{
    int power;
    power = 1;
    while (exp-- > 0)
        power *= base;

    return power;
}

// -------------------------------------------------------

int swap(char **px, char **py) /* interchange *px and *py */
{
    char *temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

// ---------------------

void reverseLines(char **array, int lines)
{
    int i, j;

    j = lines - 1;
    i = 0;
    while (i < j)
    {
        char *temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
}
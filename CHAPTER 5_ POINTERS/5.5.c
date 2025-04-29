
//Exercise 5-5. Rewrite readlines to create lines in an array supplied by main, rather than calling alloc to maintain storage. How much faster is the program?

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINES 100   
/* Nombre maximal de lignes à trier */
#define MAXLEN 1000 
/* Longueur maximale d'une ligne */
#define MAXSTORE 10000

extern char *alloc(int);

int get_line(char *s, int lim);

int sort(char *lineptr[], int nlines);

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);


char lineStore[MAXSTORE];


int main()
{
    char *lineptr[LINES]; /* Pointeurs vers les lignes de texte */
    int nlines;           /* Nombre de lignes lues */

    /* Lire les lignes, trier, et afficher le résultat */
    if ((nlines = readlines(lineptr, LINES)) >= 0)
    {
        sort(lineptr, nlines);
        writelines(lineptr, nlines);
    }
    else
    {
        printf("Erreur: trop de lignes à trier.\n");
    }

    return 0;
}

/* Fonction qui lit les lignes de l'entrée et les stocke dans lineptr */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines = 0;
    
    char *p, line[MAXLEN];

    p = lineStore;
    char *lineStop = lineStore + MAXSTORE ;

    while ((len = get_line(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines)
        {
            return -1; /* Trop de lignes */
        }
        else if(lineStore + len < lineStop)
        {
            line[len - 1] = '\0'; 
            /* Retirer le retour à la ligne */
            strcpy(p,line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}

/* Fonction qui écrit les lignes triées */
void writelines(char *lineptr[], int nlines)
{
    for (int i = 0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
    }
}

/* Fonction qui récupère une ligne d'entrée, retourne sa longueur */
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

/* Fonction de tri utilisant l'algorithme Shell sort */
int sort(char *v[], int n)
{
    int gap, i, j;
    char *temp;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            for (j = i - gap; j >= 0 && strcmp(v[j], v[j + gap]) > 0; j -= gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}

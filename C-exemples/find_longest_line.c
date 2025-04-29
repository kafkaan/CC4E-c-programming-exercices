#include <stdio.h>
#define MAXLINE 1000 /* taille maximale de la ligne d'entrée */

void main(void) /* trouver la ligne la plus longue */
{
    int len; /* longueur actuelle de la ligne */
    int max; /* longueur maximale vue jusqu'à présent */
    char line[MAXLINE]; /* ligne d'entrée actuelle */
    char save[MAXLINE]; /* ligne la plus longue, sauvegardée */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(line, save);
        }
    if (max > 0) /* il y avait une ligne */
        printf("%s", save);
}

int get_line(char s[],int lim) /* obtenir une ligne dans s, renvoyer la longueur */
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return(i);
}

void copy(char s1[], char s2[]) 
/* copier s1 dans s2 ; suppose que s2 est assez grand */
{
    int i;

    i = 0;
    while ((s2[i] = s1[i]) != '\0')
        ++i;
}

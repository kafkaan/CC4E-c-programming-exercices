
#include <stdio.h>

#define MAXLINE 1000 /* taille maximale d'une ligne d'entrée */

char line[MAXLINE]; /* ligne d'entrée */
char save[MAXLINE]; /* la ligne la plus longue est sauvegardée ici */
int max; /* longueur de la ligne la plus longue vue jusqu'à présent */

main() /* trouve la ligne la plus longue ; version spécialisée */
{
    int len;
    extern int max;
    extern char save[];
    max = 0;
    while ((len = get_line()) > 0)
        if (len > max) {
            max = len;
            copy();
        }
    if (max > 0) /* il y avait une ligne */
        printf("%s", save);
}

get_line() /* version spécialisée */
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\\0';
    return(i);
}

copy() /* version spécialisée */
{
    int i;
    extern char line[], save[];

    i = 0;
    while ((save[i] = line[i]) != '\0')
        ++i;
}

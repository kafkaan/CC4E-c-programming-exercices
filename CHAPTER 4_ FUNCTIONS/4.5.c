/*
 *   Exercise 4-5. Suppose that there will never be more than one character of pushback.
 *   Modify getch and ungetch accordingly.
 */

#include <stdio.h>
#define BUFSIZE 100

int buf = EOF; /* tampon pour ungetch */

int getch();
void ungetch(int c);

int getch()
{
    int c = (buf != EOF) ? buf : getchar();
    buf = EOF;
    return c;
}

void ungetch(int c) /* remettre un caractère en entrée */
{
    if (buf != EOF)
        printf("ungetch: trop de caractères\n");
    else
        buf = c;
}

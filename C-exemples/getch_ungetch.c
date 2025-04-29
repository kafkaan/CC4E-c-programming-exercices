#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE]; /* tampon pour ungetch */
int bufp = 0; /* position libre suivante dans buf */

getch() /* obtenir un caractère (éventuellement remis en arrière) */
{
  return((bufp > 0) ? buf[--bufp] : getchar());
}

ungetch (c) /* remettre un caractère en entrée */
int c;
{
  if (bufp > BUFSIZE)
    printf("ungetch: trop de caractères\n");
  else
    buf[bufp++] = c;
}

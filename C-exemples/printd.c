#include <stdio.h>

printd(n) /* imprimer n en décimal */
int n;
{
  char s[10];
  int i;

  if (n < 0) {
    putchar('-');
    n = -n;
  }
  i = 0;
  do {
        s[i++]  = n % 10  + '0';  /* obtenir le prochain char  */
  } while ((n  /= 10) >  0); /*  le jeter */
  while (--i >= 0)
    putchar(s[i]);
}

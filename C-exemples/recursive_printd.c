#include <stdio.h>

printd(n) /* imprimer n en décimal (récursif) */
int n;
{
  int i;

  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if ((i = n/10) != 0)
    printd(i);
  putchar(n % 10 + '0');
}

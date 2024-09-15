#include <stdio.h>

int strlen(char *s);

int main()
{
    char s[] = "Hello, World!";
    printf("%d\n", strlen(s));
    return (0);
}
//  ---------------------------------------------------

int strlen(char *s) /* return length of string s */
{
    int n;

    for (n = 0; *s != '\0'; s++)
        n++;
    return (n);
}

//  ---------------------------------------------------


strlen(s) /* retourne la longueur de la chaîne s */
char *s;
{
  char *p = s;

  while(*p != '\0')
    p++;
  return(p-s);
}

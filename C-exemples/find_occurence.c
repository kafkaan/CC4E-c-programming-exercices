#include <stdio.h>
#define MAXLINE 1000

void main(void) /* find all lines matching a pattern */
{
  char line[MAXLINE];

  while (get_line(line, MAXLINE) > 0)
    if (index(line, "the") >= 0)
      printf("%s", line);
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

index(char s[],char t[]) /* return index of t in s, -1 if none */
{
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
      ;
    if (t[k] == '\0')
      return(i);
  }
  return (-1) ;
}

#include <stdio.h>

void main(void)
{
    
}

// ------------------------------ Squeeze -------------------------
void squeeze(s, c) 
char s[];
int c;
{
  int i,  j;

  for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
  s[j] = '\0';
}

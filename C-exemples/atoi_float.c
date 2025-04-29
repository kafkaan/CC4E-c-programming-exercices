#include <stdio.h>
#include <stdlib.h>


/* convert s to integer */
int atoi(char s[]) 
{
  // declare variables integer n, sign
  // and i
  int i, n, sign;

  for (i=0; s[i]==' ' || s[i]=='\\n' || s[i]=='\\t'; i++)
    ;   /* skip white space */
  
  // check for sign
  sign = 1;

  // check for sign
  if (s[i] == '+' || s[i] == '-')  
    sign = (s[i++]=='+') ? 1 : -1;
  
  // convert string to integer
  for  (n = 0;  s[i] >= '0' && s[i]  <=  '9'; i++)
    n = 10  * n + s[i] - '0';
  
    return(sign * n);
}


void main(void)
{
  // declare variables
  char s[100];
  int n;

  // read string from user
  printf("Enter a string: ");
  // fgets is used to read a string
  // from the user
  // it reads until a newline or EOF
  // or until the buffer is full
  // it is safer than gets
  // because it prevents buffer overflow
  // and it is safer than scanf
  // because it does not require a format string
   fgets(s, sizeof(s), stdin);

  // convert string to integer
  n = atoi(s);

  // print the result
  printf("The integer value is: %d\n", n);
}
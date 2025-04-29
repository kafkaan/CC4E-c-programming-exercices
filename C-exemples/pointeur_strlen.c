int strlen(char *s) /* return length of string s */
{
  int n;

  for (n = 0; *s != '\0'; s++)
    n++;
  return (n);
}
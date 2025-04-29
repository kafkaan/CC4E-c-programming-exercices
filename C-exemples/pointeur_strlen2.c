strlen(s) /* retourne la longueur de la chaîne s */
char *s;
{
  char *p = s;

  while(*p != '\0')
    p++;
  return(p-s);
}
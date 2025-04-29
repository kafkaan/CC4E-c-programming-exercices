int getop(char s[],int lim) /* obtenir l'opérateur ou l'opérande suivant */
{
  int i, c;

  while ((c = getch()) == ' ' || c == '\t' || c == '\n')
    ;
  if (c != '.' && (c < '0' || c > '9'))
    return(c);
  s[0] = c; //car dans le getch on fait aussi un getchar donc on stocke le premier chiffre renovye
  for (i = 1; (c = getchar()) >= '0' && c <= '9'; i++)
    if (i < lim)
      s[i] = c;
  if (c == '.') {  /* collecter la fraction */
    if (i < lim)
      s[i] = c;
    for (i++; (c=getchar()) >= '0' && c <= '9'; i++)
      if (i < lim)
        s[i] = c;
  }
  if (i < lim) {  /* le nombre est correct */
    ungetch(c);
    s[i] = '\0';
    return (NUMBER);
  } else { /* il est trop grand ; sauter le reste de la ligne */
    while (c != '\n' && c != EOF)
      c = getchar();
    s[lim-1] = '\0';
    return(TOOBIG);
  }
}

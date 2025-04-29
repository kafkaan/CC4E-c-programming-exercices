 
#include <stdio.h>
#define MAXVAL 100 /* profondeur maximale de la pile de valeurs */


int sp = 0; /* pointeur de pile */
double val[MAXVAL]; /* pile de valeurs */

double push(f) /* pousser f sur la pile de valeurs */
double f;
{
  if (sp < MAXVAL)
    return(val[sp++] = f);
  else {
    printf("erreur : pile pleine\\n");
    clear();
    return(0);
  }
}

double pop() /* sortir la valeur supérieure de la pile */
{
  if (sp > 0)
    return(val[--sp]);
  else {
    printf("erreur : pile vide\\n");
    clear();
    return(0);
  }
}

clear() /* vider la pile */
{
  sp = 0;
}

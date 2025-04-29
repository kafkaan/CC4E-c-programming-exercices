#include <stdio.h>

main() /* test de la fonction power */
{
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
}

power(int x, int n) 
/* élève x à la puissance n ; n > 0 */
{
    int i, p;  // Déclaration des variables

    p = 1;  // Initialisation de la variable résultat
    for (i = 1; i <= n; ++i)
        p = p * x;  // Calcul de la puissance
    return (p);  // Renvoie du résultat
}
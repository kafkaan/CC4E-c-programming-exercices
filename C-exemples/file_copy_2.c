#include <stdio.h>

main() /* copie l'entrée vers la sortie ; 2ème version */
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
}

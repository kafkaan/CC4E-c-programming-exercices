#include <stdio.h>

void main(void) /* copie l'entrée vers la sortie ; 1ère version */
{
    int c;
    c = getchar();

    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
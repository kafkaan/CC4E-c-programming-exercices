/*
Exercise 5-1. Write getfloat, the floating point analog of get_int. What type does getfloat return as its function value?
*/

#include <stdio.h>

#define SIZE 10

int get_float(float *pf);

// ---------------------------------------------------------------------------------
int main(void)
{
    int n;
    float v, array[SIZE];

    printf("Entrez jusqu'à %d nombres à virgule flottante (Ctrl+D pour terminer) :\n", SIZE);

    // Lire des valeurs en flottant et les stocker dans le tableau
    for (n = 0; n < SIZE && get_float(&v) != EOF; n++)
    {
        array[n] = v;
    }

    // Afficher les valeurs lues
    printf("\nVous avez entré les nombres suivants :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f\n", array[i]);
    }

    return 0;
}

// ------------------------------------------------------------------------------
int get_float(float *pf)
{
    int c, sign;

    float power;

    // Ignorer les espaces blancs
    while ((c = getchar()) == ' ' || c == '\n' || c == '\t')
        ;
    sign = 1;

    if (c == '+' || c == '-')
    {
        sign = (c == '+') ? 1 : -1;
        c = getchar();
    }

    // Lire la partie entière
    for (*pf = 0; c >= '0' && c <= '9'; c = getchar())
    {
        *pf = 10 * *pf + (c - '0');
        // convert the string to float
    }

    power = 1.0;
    // power is used to store the decimal part of the float

    // Lire la partie décimale si elle existe
    if (c == '.')
    {
        while ((c = getchar()) >= '0' && c <= '9')
        {
            *pf = 10 * *pf + (c - '0');
            power *= 10;
            // convert the string to float
            // incriment the power by 10
        }
    }

    // find final float value by dividing the float by power
    *pf = sign * (*pf / power);

    // return the character or EOF if the end of the file is reached
    return c;
}

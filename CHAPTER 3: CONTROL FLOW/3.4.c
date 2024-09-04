/*
    Exercise 3-4. Write the analogous function itob(n, s)
    which converts the unsigned integer n into a binary character
    representation in s. Write itoh, which converts an integer to hexadecimal
    representation.
*/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void itob(unsigned n, char s[]);

void main(void)
{
    unsigned number;
    char str[MAXLINE];

    number = 2345645;

    printf("Integer %d printed as\n String:", number);

    itob(number, str);

    printf("%s", str);
}

void itob(unsigned int n, char s[])
{
    int i = 0;

    // Effectuer la conversion
    do
    {
        s[i++] = (n % 2) + '0'; // Ajoute le reste (0 ou 1) comme un caractère
        n /= 2;
    } while (n > 0);

    s[i] = '\0';

    reverse(s); // Inverser la chaîne pour obtenir le bon ordre
}

void itoh(unsigned int n, char s[])
{
    int i = 0;
    int remainder;

    do
    {
        remainder = n % 16;
        if (remainder < 10)
        {
            s[i++] = remainder + '0'; // Convertit les chiffres 0-9
        }
        else
        {
            s[i++] = (remainder - 10) + 'A'; // Convertit les lettres A-F
        }
        n /= 16;
    } while (n > 0);

    s[i] = '\0';

    reverse(s); // Inverser la chaîne pour obtenir le bon ordre
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

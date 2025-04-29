// Exercise 4-2. Extend atof so it handles scientific notation of the form
// 123.45e-6 where a floating point number may be followed by e or E and an optionally signed exponent.

#include <stdio.h> // Inclut la bibliothèque standard input-output
#include <ctype.h>
double atof(char s[]); // Déclare la fonction atof qui prend une chaîne de caractères et renvoie un double

int powerExp(int base, int exp);

int main(void)
{                           // Définit la fonction main
    char s[] = "123.45e-6"; // Déclare une chaîne de caractères s contenant un nombre
    double d = atof(s);     // Convertit la chaîne de caractères en double
    printf("%f\n", d);      // Affiche le double
    return 0;               // Renvoie 0 pour indiquer que tout s'est bien passé
}

double atof(char s[])
{                      // Déclare la fonction atof qui prend une chaîne de caractères et renvoie un double
    double val, power; // Déclare deux variables de type double
    int i, sign;       // Déclare deux variables de type int

    int e_sign = 1;
    int exp = 0;

    for (i = 0; s[i] == ' ' || s[i] == '\\n' || s[i] == '\\t'; i++) // Boucle qui saute les espaces blancs en début de chaîne
        ;                                                           // Ne fait rien dans le corps de la boucle

    sign = 1; // Initialise le signe à 1 (pour un nombre positif)

    if (s[i] == '+' || s[i] == '-')      // Si le caractère courant est '+' ou '-', il détermine le signe du nombre
        sign = (s[i++] == '+') ? 1 : -1; // Si le caractère est '+', le signe reste 1, sinon il devient -1

    for (val = 0; s[i] >= '0' && s[i] <= '9'; i++) // Boucle qui parcourt les chiffres du nombre
        val = 10 * val + s[i] - '0';               // Convertit chaque chiffre en int et l'ajoute à val

    if (s[i] == '.') // Si le caractère courant est un point, il passe au caractère suivant
        i++;

    for (power = 1; s[i] >= '0' && s[i] <= '9'; i++)
    {                                // Boucle qui parcourt les chiffres après le point
        val = 10 * val + s[i] - '0'; // Convertit chaque chiffre en int et l'ajoute à val
        power *= 10;                 // Augmente la puissance de 10 à chaque itération
    }

    if (s[i] == 'E' || s[i] == 'e')
    {
        i++;
    }

    else if (s[i] == '-' || s[i] == '+')
    {
        e_sign = s[i];
    }

    for (exp = 0; isdigit(s[i]); i++)
    {
        exp = 10 * exp + (s[i] - '0');
    }

    if (e_sign == '-')
        return sign * (val / power) / powerExp(10, exp);
    else

        return sign * (val / power) * powerExp(10, exp);
}

int powerExp(int base, int exp)
{
    int power;
    power = 1;
    while (exp-- > 0)
        power *= base;

    return power;
}
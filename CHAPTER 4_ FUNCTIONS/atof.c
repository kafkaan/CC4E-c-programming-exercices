#include <stdio.h> // Inclut la bibliothèque standard input-output

double atof(char s[]); // Déclare la fonction atof qui prend une chaîne de caractères et renvoie un double

int main(void)
{                        // Définit la fonction main
    char s[] = "123.45"; // Déclare une chaîne de caractères s contenant un nombre
    double d = atof(s);  // Convertit la chaîne de caractères en double
    printf("%f\n", d);   // Affiche le double
    return 0;            // Renvoie 0 pour indiquer que tout s'est bien passé
}

double atof(char s[])
{                      // Déclare la fonction atof qui prend une chaîne de caractères et renvoie un double
    double val, power; // Déclare deux variables de type double
    int i, sign;       // Déclare deux variables de type int

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

    return (sign * val / power); // Renvoie le nombre final, qui est le produit du signe, de val et de l'inverse de power
}

int atoi(s) /* convertir la chaîne s en entier */
char s[];
{
    double atof();

    return (atof(s));
}
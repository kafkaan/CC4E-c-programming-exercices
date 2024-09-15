#include <stdio.h>

/* Concatenate t to the end of s. Assumes that s has enough space */
void strcat(char *s, const char *t)
{
    // Avancer s jusqu'à la fin de la chaîne (caractère nul '\0')
    while (*s)
        s++; // On avance jusqu'à la fin de la chaîne

    // Copier t dans s (y compris le caractère nul)
    while ((*s++ = *t++))
        ;
}

int main(void)
{
    char s[100] = "Bonjour "; // Chaine de destination avec assez d'espace
    char t[] = "monde!";      // Chaine source

    printf("Avant strcat:\n");
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // Appel de la fonction strcat pour concaténer t à la fin de s
    strcat(s, t);

    printf("\nAprès strcat:\n");
    printf("s: %s\n", s); // Doit afficher "Bonjour monde!"

    return 0;
}

// Exercise 5-2. Write a pointer version of the function strcat which we showed in Chapter 2: strcat(s, t) copies the string t to the end of s.
#include <stdio.h>



void strcat(char *s, const char *t)
{
    // Avancer s jusqu'à la fin de la chaîne (caractère nul '\0')
    while (*s)
        s++; 

    // Copier t dans s (y compris le caractère nul)
    while ((*s++ = *t++))
        ;
}


// ----------------------------------- MAIN ----------------------------------------------- //
int main(void)
{
    char s[100] = "Bonjour "; 
    char t[] = "monde!";      

    printf("Avant strcat:\n");
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    strcat(s, t);

    printf("\nAprès strcat:\n");
    printf("s: %s\n", s); 
    // Must see : "Bonjour monde!"

    return 0;
}

#include <stdio.h>
#include <string.h> // Pour strcpy

#define MAXLINE 1000

void expand(char s1[], char s2[]);

int main(void)
{
    char s[MAXLINE];
    char t[MAXLINE];

    // Test cases
    strcpy(s, "a-z");
    expand(s, t);
    printf("Expanded 'a-z': %s\n", t);

    strcpy(s, "z-a");
    expand(s, t);
    printf("Expanded 'z-a': %s\n", t);

    strcpy(s, "a-z0-9");
    expand(s, t);
    printf("Expanded 'a-z0-9': %s\n", t);

    strcpy(s, "-a-z");
    expand(s, t);
    printf("Expanded '-a-z': %s\n", t);

    strcpy(s, "a-b-c");
    expand(s, t);
    printf("Expanded 'a-b-c': %s\n", t);

    return 0;
}

void expand(char s1[], char s2[])
{
    int i = 0, j = 0;

    while (1)
    {
        if (s1[i] == '\0') // Si on atteint la fin de la chaîne
        {
            break;
        }

        if (s1[i] != '-')
        {
            char first = s1[i++];
            s2[j++] = first; // Copie le premier caractère dans s2

            if (s1[i] == '-' && s1[i + 1] != '\0' && s1[i + 1] != '-') // Vérifie qu'il y a une plage à étendre
            {
                i++; // Passe le '-'
                char last = s1[i++];

                if (first < last) // Si la plage est croissante, par ex. a-z
                {
                    while (first < last)
                    {
                        s2[j++] = ++first; // Ajoute les caractères dans l'ordre
                    }
                }
                else if (first > last) // Si la plage est décroissante, par ex. z-a
                {
                    while (first > last)
                    {
                        s2[j++] = --first; // Ajoute les caractères dans l'ordre inverse
                    }
                }
            }
        }
        else // Gérer le cas où '-' est au début ou à la fin de la chaîne, ou à côté d'un autre '-'
        {
            s2[j++] = s1[i++]; // Copie simplement le '-'
        }
    }

    s2[j] = '\0'; // Termine la chaîne s2
}

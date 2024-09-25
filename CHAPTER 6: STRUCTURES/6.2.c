#include <ctype.h>

#define LETTER 'a'
#define DIGIT  '0'

int type(int c) {
    if (isalpha(c))         // Vérifie si c'est une lettre, peu importe le jeu de caractères
        return LETTER;
    else if (isdigit(c))    // Vérifie si c'est un chiffre
        return DIGIT;
    else
        return c;           // Sinon, renvoie le caractère lui-même
}

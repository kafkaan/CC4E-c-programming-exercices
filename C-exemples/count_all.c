#include <stdio.h>

// Définition de constantes pour améliorer la lisibilité du code
#define YES 1
#define NO  0

int main() {
    // --- DECLARATION DES VARIABLES -----
    int c, nl, nw, nc, inword;

    // Initialisation des variables
    inword = NO;
    nl = nw = nc = 0;

    // Boucle principale pour lire les caractères jusqu'à la fin du fichier (EOF)
    while ((c = getchar()) != EOF) {
        ++nc; 
        // Compteur du nombre total de caractères

        // Vérification si le caractère est une nouvelle ligne
        if (c == '\n')
            ++nl; 

        // si le caractère est un espace, une tabulation ou une nouvelle                               ligne
        if (c == ' ' || c == '\n' || c == '\t')
            inword = NO; 
        
        // Si c'est le cas, on indique que nous ne sommes plus dans un mot
        else if (inword == NO) {
            // Si le caractère n'est pas un espace, une tabulation ou une nouvelle ligne,
            // et que nous n'étions pas dans un mot précédemment, cela signifie que nous avons commencé un nouveau mot
            inword = YES; 
            ++nw; 
        }
    }

    // Affichage du nombre total de lignes, de mots et de caractères
    printf("%d %d %d\n", nl, nw, nc);

    return 0;
}
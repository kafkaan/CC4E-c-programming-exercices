#include <stdio.h>

void main(void) 
/* compte les chiffres, les espaces et les autres caractères */
{
    int c, i, nwhite, nother;  
    // Déclaration des variables
    
    int ndigit[10];  
    // Tableau pour compter les chiffres de 0 à 9

    nwhite = nother = 0;  
    // Initialisation des compteurs
    
    // ---------------------------------
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;  
        // Initialisation du tableau à zéro

    while ((c = getchar()) != EOF)  
    // Boucle de lecture des caractères jusqu'à la fin de fichier (EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];  
            // Incrémentation du compteur du chiffre rencontré
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;  
        else
            ++nother;  

    printf("chiffres =");

    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);  
        // Affichage du nombre d'occurrences de chaque chiffre

    printf("\n espace = %d, autre = %d\n",nwhite, nother);  
    // Affichage du nombre d'espaces et du nombre d'autres caractères
}
#include <stdio.h>
#include <stdlib.h>

// Structure pour représenter une date
struct date
{
    int day;
    int month;
    int year;
    int yearday;     // Numéro du jour dans l'année
    char mon_name[4]; // Nom du mois (non utilisé ici)
};

// Tableau des jours par mois, avec une entrée pour les années non bissextiles et bissextiles
static int day_tab[2][13] =
    {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // Année normale
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  // Année bissextile
    };

// Fonction pour calculer le numéro du jour dans l'année
int day_of_year(struct date *pd)
{
    int i, day, leap;

    // Calculer si l'année est bissextile
    leap = (pd->year % 4 == 0 && pd->year % 100 != 0) || (pd->year % 400 == 0);
    
    // Initialiser le jour avec le jour du mois
    day = pd->day;
    
    // Ajouter les jours des mois précédents
    for (i = 1; i < pd->month; i++)
    {
        day += day_tab[leap][i];
    }
    
    return day;
}

// Fonction principale pour tester le programme
int main(void)
{
    struct date my_date;
    
    // Lecture des données de l'utilisateur
    printf("Entrez le jour (1-31) : ");
    scanf("%d", &my_date.day);
    printf("Entrez le mois (1-12) : ");
    scanf("%d", &my_date.month);
    printf("Entrez l'année : ");
    scanf("%d", &my_date.year);
    
    // Calcul du jour de l'année
    my_date.yearday = day_of_year(&my_date);
    
    // Affichage du résultat
    printf("Le jour %d/%d/%d est le jour numéro %d de l'année.\n", my_date.day, my_date.month, my_date.year, my_date.yearday);
    
    return 0;
}

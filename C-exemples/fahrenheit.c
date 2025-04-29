#include <stdio.h>

main()
{
    /* ------------------------ déclaration des variables ---------------- */
    int lower, upper, step;
    
    float fahr, celsius; 
    
   
		
    // -------------- attribution des valeurs : initialisation ------------
    
    lower = 0; 
    /* lower limit of temperature table */
    upper = 300; 
    /* upper limit */
    step = 20; 
    /* step size */
    fahr = lower;

    while (fahr <= upper) { 
        // boucle qui créer une intervalle d'itération TOP TESTED
        celsius = (5.0/9.0) * (fahr-32.0); 
        // on calcule la valeur
        printf("%4.0f %6.1f\\n", fahr, celsius); 
        /* four number before fahr and 0 after . ) */
        fahr = fahr + step;
    }
}
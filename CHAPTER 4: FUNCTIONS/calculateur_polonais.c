
#include <stdio.h>

#define MAXOP 20 /* taille maximale de l'opérande, de l'opérateur */
#define NUMBER '0' /* signal qu'un nombre a été trouvé */ *
#define TOOBIG '9' /* signal que la chaîne est trop grande */

extern int getop(char[], int);
extern double push(double);
extern void clear(void);

void main(void) /* calculatrice polonaise inversée */
{
    int type;
    char s[MAXOP];
    double op2, atof(), pop(), push();

    while ((type = getop(s, MAXOP)) != EOF)
        switch (type)
        {

        case '0':
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("diviseur zéro détecté\\n");
            break;
        case '=':
            printf("\\t%f\\n", push(pop()));
            break;
        case 'c':
            clear();
            break;
        case TOOBIG:
            printf("%.20s ... est trop long\\n", s);
            break;
        default:
            printf("commande inconnue %c\\n", type);
            break;
        }
}

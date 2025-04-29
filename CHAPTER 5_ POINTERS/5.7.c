
/*

Exercise 5-7. Write the program add which evaluates a reverse Polish expression from the command line. For example,

add 2 3 4 + *

evaluates 2 * (3+4).

*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 1000
#define MAXOP 100

//-----------------------------------------------------------

int getch(void);
void ungetch(int c);

int getop(char *s);

void push(double number);
double pop(void);

void ungets(char *s);

// ---------------------------------------------------------------------

int sp = 0;
int bufp = 0;

double val[MAXVAL];
char buf[BUFSIZE];

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <reverse Polish expression>\n", argv[0]);
        return 1;
    }

    argv++; // Skip program name
    int type;
    double op2;
    char s[MAXOP];

    while (--argc > 0)
    {
        ungets(*argv++); // Passe l'argument sous forme de chaîne

        while ((type = getop(s)) != EOF)
        {
            switch (type)
            {
            case NUMBER:
                push(atof(s)); // Convertit la chaîne en nombre et pousse dans la pile
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
                    printf("error: zero divisor\n");
                break;
            default:
                printf("error: unknown command %c\n", type);
                break;
            }
        }
    }

    printf("Result: %.8g\n", pop());
    return 0;
}

// ---------------------- Get operand ---------------------------
int getop(char *s)
{
    int c;
    
    // Ignore les espaces et tabulations
    while ((*s = c = getch()) == ' ' || c == '\t')
        ;

    // Assure-toi que le caractère suivant est bien le caractère de fin
    *(s + 1) = '\0';

    // Si ce n'est pas un chiffre et ce n'est pas '.', alors c'est un opérateur
    if (!isdigit(c) && c != '.')
    {
        return c;  // Renvoie l'opérateur ou caractère non numérique
    }

    // Sinon, c'est un nombre : lis le nombre entier ou décimal
    if (isdigit(c) || c == '-') 
    // Check si c'est un nombre ou un nombre négatif
    {
        while (isdigit(*++s = c = getch()))
            ;

        if (c == '.')  // Si on rencontre un point décimal
        {
            while (isdigit(*++s = c = getch()))
                ; // Lis les chiffres après la décimale
        }
        *s = '\0'; // Fin de la chaîne de caractères pour le nombre
    }

    // Si le caractère lu n'est pas EOF, remets-le dans le tampon
    if (c != EOF)
    {
        ungetch(c);
    }
    return NUMBER; // Indique qu'on a lu un nombre
}

//  ----------------- Stack Operations -------------------------
void push(double number)
{
    if (sp < MAXVAL)
    {
        val[sp++] = number;
    }
    else
    {
        printf("ERROR : Stack full, can't push %g\n", number);
    }
}

double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("ERROR : Stack EMPTY\n");
        return 0.0;
    }
}

// --------------------------- Buffer for getchar/ungetch -------------

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();  // Remplace getchar() par EOF si on veut arrêter la lecture
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

// Ungets entire string to buffer
void ungets(char s[])
{
    char *t = s;

    while(*t)
    {
        t++;
    }

    while(t >s)
    {
        ungetch(*--t);
    }
}

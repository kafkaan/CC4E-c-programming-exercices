#include <stdio.h>

get_int(pn) /* obtenir le prochain entier de l'entrée */
    int *pn;
{
    int c, sign;

    while ((c = getch()) == ' ' || c == '\\n' || c == '\\t')
        ;
    /* passer les espaces blancs */
    sign = 1;

    if (c == '+' || c == '-')
    { /* enregistrer le signe */
        sign = (c == '+') ? 1 : -1;
        c = getch();
    }
    for (*pn = 0; c >= '0' && c <= '9'; c = getch())
        *pn = 10 * *pn + c - '0';

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return (c);
}
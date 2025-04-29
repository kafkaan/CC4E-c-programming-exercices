/******************************************************************************

    Pattern Matching Program
    Exercise 5-4: Rewrite programs using pointers instead of array indexing.
    Includes: get_line, atoi, itoa, reverse, strindex, getop

*******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// --------------------------------------------------------------------------------------
// 📌 Constants and buffer definitions
// --------------------------------------------------------------------------------------

#define NUMBER '0'
// signal that a number was found
#define MAXVAL 100
// maximum depth of val stack
#define BUFSIZE 100
#define MAXLINE 1000
#define MAXOP 100

// --------------------------------------------------------------------------------------
// 📌 Function declarations
// --------------------------------------------------------------------------------------

int getch(void);
void ungetch(int);

int getop(char *);

int mgetline(char *s, int lim);

int strindex(char *s, char *t);

int atoiv2(char *);
void itoav2(int n, char *s);

void reverse(char *);

// --------------------------------------------------------------------------------------
// 📌 Global variables
// --------------------------------------------------------------------------------------

int sp = 0;
// stack pointer
int bufp = 0;
// next free position in buf

double val[MAXVAL];
// value stack
char buf[BUFSIZE];
// input buffer

char pattern[] = "ould"; // pattern to search for

// --------------------------------------------------------------------------------------
// 📌 Main function
// --------------------------------------------------------------------------------------

int main(void)
{

    // Test de atoiv2
    char *s = "1234";
    printf("\n🔢 atoi(\"%s\") = %d\n", s, atoiv2(s));

    // Test de itoav2 + reverse
    int i = 12345;
    char s1[100];
    itoav2(i, s1);
    reverse(s1);
    printf("🔄 itoa + reverse : %s\n", s1);

    char number[] = "12345";
    reverse(number);
    printf("Reverse : %s\n", number);

    // Test de strindex
    char *s2 = "This is a line";
    char *t = "is";
    printf("🔍 strindex(\"%s\", \"%s\") = %d\n", s2, t, strindex(s2, t));

    return 0;
}

// --------------------------------------------------------------------------------------
// 📌 ATOI version pointeur
// --------------------------------------------------------------------------------------

int atoiv2(char *s)
{
    int n, sign;

    while (isspace(*s))
        s++;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;

    for (n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');

    return sign * n;
}

// --------------------------------------------------------------------------------------
// 📌 getop — Get next operator or operand (pointer version)
// --------------------------------------------------------------------------------------

int getop(char *s)
{
    int c;

    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s + 1) = '\0';

    if (!isdigit(c) && c != '.')
        return c;

    if (isdigit(c))
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.')
        while (isdigit(*++s = c = getch()))
            ;

    *s = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

// --------------------------------------------------------------------------------------
// 📌 getch / ungetch
// --------------------------------------------------------------------------------------

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("❌ ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

// --------------------------------------------------------------------------------------
// 📌 itoa version pointeur
// --------------------------------------------------------------------------------------

void itoav2(int n, char *s)
{
    int sign;
    char *t = s;

    if ((sign = n) < 0)
        n = -n;

    do
    {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        *s++ = '-';

    *s = '\0';
    reverse(t);
}

// --------------------------------------------------------------------------------------
// 📌 reverse d'une chaîne (pointeur)
// --------------------------------------------------------------------------------------

void reverse(char *s)
{
    int c;
    char *t;

    for (t = s + strlen(s) - 1; s < t; s++, t--)
    {
        c = *s;
        *s = *t;
        *t = c;
    }
}

// --------------------------------------------------------------------------------------
// 📌 mgetline — lire une ligne jusqu’à 'X' ou newline
// --------------------------------------------------------------------------------------

int mgetline(char *s, int lim)
{
    int c;
    char *t = s;

    while (--lim > 0 && (c = getchar()) != 'X' && c != '\n')
        *s++ = c;

    if (c == '\n')
        *s++ = c;

    *s = '\0';
    // return here the length of the line
    return s - t;
}

// --------------------------------------------------------------------------------------
// 📌 strindex — trouver l’indice d’une sous-chaîne (version pointeur)
// --------------------------------------------------------------------------------------

int strindex(char *s, char *t)
{
    char *b = s;
    char *p, *r;

    for (; *s != '\0'; s++)
    {
        for (p = s, r = t; *r != '\0' && *p == *r; p++, r++)
            ;

        if (r > t && *r == '\0')
            return s - b;
    }
    return -1;
}

//mine
int strindex(char *s, char *t)
{
    char *temp1 = s;
    char *temp2 = t;

    char *p;
    char *p2;

    for (; *temp1; temp1++)
    {
        for (p = temp1, p2 = temp2; *p2 && (*p2 == *p); p2++, p++)
            ;
        if (*p2 == '\0' && p2 > temp2 )
        {
            return temp1 - s; // trouvé !
        }
    }
    return -1; // pas trouvé
}

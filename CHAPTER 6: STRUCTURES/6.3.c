#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define LETTER 'a'
#define DIGIT '0'
#define MAXWORD 1000
#define BUFSIZE 10000
#define NKEYS (sizeof(keytab) / sizeof(struct key))

struct key
{
    char *keyword;
    int keycount;
} keytab[] = {
    "break", 0,
    "case", 0,
    "char", 0,
    "continue", 0,
    "default", 0,
    "unsigned", 0,
    "while", 0};

int getword(char *w, int lim);
int getch(void);
void ungetch(int c);
int binary(char *word, struct key tab[], int n);

int bufp = 0;
char buf[BUFSIZE];

int main(void)
{
    int n, t;
    char word[MAXWORD];
    int inside_quote = 0;

    while ((t = getword(word, MAXWORD)) != EOF)
    {
        if (t == '\"')
        {
            inside_quote = !inside_quote; // Toggle quote status
        }
        if (!inside_quote && t == LETTER)
        {
            if ((n = binary(word, keytab, NKEYS)) >= 0)
            {
                keytab[n].keycount++;
            }
        }
    }

    for (n = 0; n < NKEYS; n++)
    {
        if (keytab[n].keycount > 0)
        {
            printf("%4d %s\n", keytab[n].keycount, keytab[n].keyword);
        }
    }

    return 0;
}

int getword(char *w, int lim) /* get next word from input */
{
    int c, t;
    if (!isalpha(c = *w++ = getch()))
    {
        *w = '\0';
        return (c);
    }

    while (--lim > 0)
    {
        t = isalnum(c = *w++ = getch());
        if (!t)
        {
            ungetch(c);
            break;
        }
    }
    *(w - 1) = '\0';
    return (LETTER);
}

// --------------------------- Buffer for getchar/ungetch -------------

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar(); // Remplace getchar() par EOF si on veut arrêter la lecture
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

// --------------------------------------------------------------

int binary(char *word, struct key tab[], int n) /* find word in tab[0]...tab[n-1] */
{
    int low, high, mid, cond;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].keyword)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return (mid);
    }
    return (-1);
}

// ###########################################################
int type(int c) /* return type of ASCII character */
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        return (LETTER);

    else if (c >= '0' && c <= '9')
        return (DIGIT);
    else
        return (c);
}


/* get next word from input */
int getwordv2(char *w, int lim) 
{
    int c, t;
    if (type(c = *w++ = getch()) != LETTER)
    {
        *w = '\0';
        return (c);
    }

    while (--lim > 0)
    {
        t = type(c = *w++ = getch());
        if (t != LETTER && t != DIGIT)
        {
            ungetch(c);
            break;
        }
    }
    *(w - 1) = '\0';
    return (LETTER);
}
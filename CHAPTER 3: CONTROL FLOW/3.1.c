/*
 *Exercise 3-1. Write a function expand(s, t) which converts characters like newline and tab into
 *visible escape sequences like \n and \t as it copies the string s to t. Use a switch.
 */

#include <stdio.h>

#define MAXLINE 1000

void expand(char *s, char *t);

void main()
{
    char s[MAXLINE] = "Hello\tWorld\n";
    char t[MAXLINE];
    expand(s, t);
    printf("%s", t);
}

void expand(char *s, char *t)
{
    int i, j = 0;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (j >= MAXLINE - 2) // 2 car certains caractères sont remplacés par deux autres
        {
            // Gerer l'erreur: buffer trop petit
            break;
        }
        switch (s[i])
        {
        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            break;
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;
        case '\r':
            t[j++] = '\\';
            t[j++] = 'r';
            break;
        case '\b':
            t[j++] = '\\';
            t[j++] = 'b';
            break;
        case '\\':
            t[j++] = '\\';
            t[j++] = '\\';
            break;
        default:
            t[j++] = s[i];
            break;
        }
    }
    t[j] = '\0'; // Terminaison de la chaîne
}

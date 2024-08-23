
//Exercise 1-15. Write a program to print all lines that are longer than 80 characters.


#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define THRESHOLD 80 /* minimum line length to be printed for Exercise 1-15 */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;            /* current line length */
    int max;            /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char save[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(save, line);
        }

        /* Print lines longer than 80 characters */
        if (len > THRESHOLD)
        {
            printf("Length: %d\n", len);
            printf("Line: %s", line);
        }
    }

    if (max > 0)
    { /* There was a line */
        printf("\nLongest line length: %d\n", max);
        printf("Longest line: %s", save);
    }

    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i, extra_len = 0;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    /* Count remaining characters if line is longer than lim */
    if (i == lim - 1 && c != EOF && c != '\n')
    {
        while ((c = getchar()) != EOF && c != '\n')
        {
            ++extra_len;
        }
        if (c == '\n')
        {
            ++extra_len;
        }
    }

    return i + extra_len;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}

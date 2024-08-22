// Exercise 2.2 - Write getline without && and || operator

#include <stdio.h>

#define MAXLINE 1000

int mgetline(char line[], int lim);

//void copy(char to[], const char from[]);

int main(void)
{
    int len, max;
    char line[MAXLINE], maxline[MAXLINE];

    max = 0;

    while ((len = mgetline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(maxline, line);
        }
    }

    if (max > 0)
    {
        printf("%s", maxline);
    }
}

int mgetline(char line[], int lim)
{
    int i, c;

    for (i = 0; i < lim - 1; ++i)
    {
        c = getchar();
        if (c == EOF)
        {
            break;
        }

        if (c == '\n')
        {
            break;
        }
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

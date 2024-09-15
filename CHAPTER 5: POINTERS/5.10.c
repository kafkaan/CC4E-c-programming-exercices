#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINES 10 /* default # of lines to print */
#define LINES 100   /* maximum # of lines to print */
#define MAXLEN 100  /* maximum length of an input line */

int getLine(char *s, int lim);

int main(int argc, char *argv[])
{
    char line[MAXLEN];
    char *linesPtr[LINES];
    int n, len, indexLines;
    indexLines = 0;

    if (argc == 1)
    {
        n = DEFLINES;
    }
    else if (argc == 2 && argv[1][0] == '-' && argv[1][1] != '\0')
    {
        n = atoi(argv[1] + 1);
        if (n < 1 || n > LINES)
        {
            fprintf(stderr, "Error: Invalid number of lines. Using default of %d.\n", DEFLINES);
            n = DEFLINES;
        }
    }
    else
    {
        fprintf(stderr, "Usage: %s [-n]\n", argv[0]);
        return 1;
    }

    for (int i = 0; i < LINES; i++)
    {
        linesPtr[i] = NULL;
    }

    while ((len = getLine(line, MAXLEN)) > 0)
    {
        if (indexLines >= LINES)
        {
            // Remove the oldest line and shift the rest up
            free(linesPtr[0]);
            for (int i = 0; i < LINES - 1; i++)
            {
                linesPtr[i] = linesPtr[i + 1];
            }
            indexLines--;
        }
        char *newLine = malloc(len + 1);
        if (newLine == NULL)
        {
            perror("Error: Out of memory");
            exit(1);
        }
        strcpy(newLine, line);
        linesPtr[indexLines++] = newLine;
    }

    int first = indexLines - n;
    if (first < 0)
        first = 0; // Ensure first is not negative

    for (int j = first; j < indexLines; j++)
    {
        printf("%s", linesPtr[j]);
        free(linesPtr[j]); // Free the allocated memory after printing
    }

    return 0;
}

int getLine(char *s, int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        *s++ = c;
    }

    if (c == '\n')
    {
        *s++ = c;
        i++;
    }

    *s = '\0';
    return i;
}

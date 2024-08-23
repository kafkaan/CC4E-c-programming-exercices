#include <stdio.h>

#define YES 1
#define NO 0

int main() /* count lines, words, chars in input */
{
    int c, nl, nw, nc, inword, isWordValid;

    inword = NO;
    isWordValid = YES; /* Assume the word is valid initially */
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF)
    {
        ++nc;

        if (c == '\n') /* Increment line count */
            ++nl;

        if (c == ' ' || c == '\n' || c == '\t') /* Word boundary detected */
        {
            if (inword == YES)
            {
                if (isWordValid == YES) /* Only count valid words */
                    ++nw;
                inword = NO;
                isWordValid = YES; /* Reset for the next word */
            }
        }
        else
        {
            if (inword == NO) /* Beginning of a new word */
            {
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                {
                    inword = YES;      /* We are inside a word */
                    isWordValid = YES; /* It's valid so far */
                }
                else if (c >= '0' && c <= '9')
                {
                    inword = YES;
                    isWordValid = NO; /* Starts with a digit, invalid word */
                }
            }
            else if (inword == YES) /* We're inside a word, check for validity */
            {
                if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '\''))
                {
                    isWordValid = NO; /* Contains an invalid character */
                }
            }
        }
    }

    if (inword == YES && isWordValid == YES)
        ++nw; /* Count the last word if it's valid */

    printf("%d %d %d\n", nl, nw, nc);
}
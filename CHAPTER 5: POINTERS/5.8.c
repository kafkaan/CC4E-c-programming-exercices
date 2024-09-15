/**
 * Exercise 1.20 -
 *
 * Write a Program detab, which replaces tabs in the input with a proper
 * number of blanks to spaces
 *
 **/

#include <stdio.h>

#define TABINC 8

int main(int argc,char *argv[]) {
    int nb, pos, c;

    nb = 0;
    pos = 1;
    argv++;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int tabInc = (argc > 1) ? atoi(*argv++) : TABINC;
            nb = tabInc - ((pos - 1) % tabInc);

            while (nb > 0) {
                putchar('#');
                ++pos;
                --nb;
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            ++pos;
        }
    }

    return 0;
}
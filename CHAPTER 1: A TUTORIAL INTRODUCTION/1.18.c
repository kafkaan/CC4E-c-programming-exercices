#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

char line[MAXLINE]; /* input line */
char save[MAXLINE]; /* longest line saved here */
int max; /* length of longest line seen so far */

/* Function prototypes */
int get_line(void); /* Get a line of input */
void copy(void);    /* Copy the current line to the longest line */

int main() /* find longest line; specialized version */
{
    int len;

    max = 0; /* Initialize max length to 0 */
    while ((len = get_line()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }
    if (max > 0) /* there was a line */
        printf("%s", save);

    return 0;
}

/* get_line: read a line into line, return length */
int get_line(void) {
    int c, i;

    i = 0;
    while (i < MAXLINE - 1) {
        c = getchar();
        if (c == EOF) {
            break; /* End of file */
        }
        if (c == '\n') {
            break; /* End of line */
        }
        line[i++] = c;
    }

    if (c == '\n') {
        line[i++] = c; /* Include newline in the line */
    }

    line[i] = '\0'; /* Null-terminate the string */
    return i; /* Return length of the line */
}

/* copy: copy the current line to the save */
void copy(void) {
    int i;

    i = 0;
    while ((save[i] = line[i]) != '\0') {
        ++i;
    }
}

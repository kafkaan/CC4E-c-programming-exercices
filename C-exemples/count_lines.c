#include <stdio.h>

int main(void) {
    // count lines
    int c, nl;

    // Initialize line count
    nl = 0;

    // loop read characters until EOF
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);

    return 0;
}
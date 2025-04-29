
#include <stdio.h>

void main(void) {
    double nc;
    // declare variable nc

    // read characters from user
    // until EOF is reached
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}
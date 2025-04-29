#include <stdio.h>

int lower(int c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    } else {
        return c;
    }
}

int main() {
    int c;

    // Read input character by character until EOF
    while ((c = getchar()) != EOF) {
        putchar(lower(c)); // Convert to lowercase and print the result
    }

    return 0;
}

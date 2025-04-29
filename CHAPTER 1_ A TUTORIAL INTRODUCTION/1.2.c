//Exercise 1-2. Experiment to find out what happens when printf's argument string contains \x, where x is some character not listed above.

#include <stdio.h>

main() {
    //printf("hello, world\x\n");
}

// Answer:
// The program does not compile. The error message is:
// 1.2.c: In function ‘main’: \x used with no following hex digits
// The error message is self-explanatory. The escape sequence \x must be followed by one or more hexadecimal digits.
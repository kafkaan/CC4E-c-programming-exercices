#include <stdio.h>

unsigned getbits(unsigned x, unsigned p, unsigned n);

int main()
{
    unsigned x = 0b10101101;
    unsigned p = 3;
    unsigned n = 3;

    printf("%d\n", getbits(x, p, n));
}

unsigned getbits(x, p, n) /* get n bits from position p */
unsigned x, p, n;
{
    return ((x >> (p + 1 - n)) & ~(~0 << n));
}
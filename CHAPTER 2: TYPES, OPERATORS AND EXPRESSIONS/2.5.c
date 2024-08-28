/*
Exercise 2-5. Modify getbits to number bits from left to right.
*/
#include <stdio.h>

unsigned getbits(unsigned x, unsigned p, unsigned n);

int main()
{
    unsigned x = 0b10101101;
    unsigned p = 3;
    unsigned n = 3;

    printf("%d\n", getbits(x, p, n));
}

unsigned getbits(unsigned x, unsigned p, unsigned n)
{
    int bits = sizeof(x) * 8;
    // size of x is multiplied by 8 to get the number of bits in x
    // for example, if x is 4 bytes, then it has 32 bits
    return (x >> (bits - p - n)) & ~(~0 << n);
}

/*
 * Exercise 2-7 Exercise 2-7. Write the function rightrot(n, b) which rotates the integer n to 
   the right by b bit positions.


 */

#include <stdio.h>

int wordlength();
int rightrot(int x, int n);


int main()
{
    printf("Word length: %d\n", wordlength());
}

int wordlength(void)
{
    unsigned x = (unsigned)~0;
    int i;

    for (i = 0; (x = x >> 1) > 0; i++)
    {
        ;
    }

    return i;
}


int rightrot(int x, int n)
{
    int word_length = wordlength();
    return (x >> n) | (x << (word_length - n));
}

unsigned rightrot(unsigned x, int n) {
    int wordlength(void);
    unsigned rbit; /* rightmost bit */

    rbit = x << (wordlength() - n);
    x = x >> n;
    x = x | rbit;

    return x;
}
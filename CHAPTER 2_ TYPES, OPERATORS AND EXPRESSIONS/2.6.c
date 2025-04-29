/*
 * Exercise 2-6. Write a function wordlength() which computes the word length of the host machine,
 * that is, the number of bits in an int. The function should be portable, in the sense that the
 * same source code works on all machines.
 */

#include <stdio.h>

int wordlength();

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
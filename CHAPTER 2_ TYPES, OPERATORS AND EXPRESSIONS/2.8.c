/**
 *
 * Exercise 2.7
 *
 * Write a function invert(x,p,n) that returns x with n bit starting at p
 * inverted .
 *
 **/

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void) { printf("%u", (unsigned)invert((unsigned)8, (int)3, (int)3)); }

unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p + 1 - n));
    // en premier on inverse 0 donc on a 1111 1111 puis on decale par l nombre de chiffre que on veut
    //  on a 1111 1000
    // on va reinverser les 3 chifres pour avoir les 1 donc on a 0000 0111
    // le but est de mettre ces 3 111 au position a partir du quel on veut inverser
    // on se trouve avec 0001 1100
    // le ou exclusif va nous donner le resultat
}
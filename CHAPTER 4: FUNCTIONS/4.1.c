// rindex(s, t)
/*
    * Exercise 4-1. Write the function rindex(s, t), which returns the position of the rightmost occurrence of 
    * t in s, or -1 if there is none.
*/


#include <stdio.h>

int rindex(char s[], char t[]) /* return rigthest index of t in s, -1 if none */

{
    int i, j, k;

    int right_index = -1;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (t[k] == '\0')
            right_index = i;
    }
    return right_index;
}
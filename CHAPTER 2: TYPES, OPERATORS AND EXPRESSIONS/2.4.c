#include <stdio.h>

int any(char *s1, char *s2);

void main(void)
{
    char *s1 = "example";
    char *s2 = "e";
    int res = any(s1, s2);
    printf("Test 1: Result: %d (Expected: 0)\n", res); // Output should be 0

    char *s3 = "example";
    char *s4 = "x";
    int res2 = any(s3, s4);
    printf("Test 2: Result: %d (Expected: 1)\n", res2); // Output should be 1

    char *s5 = "example";
    char *s6 = "z";
    int res3 = any(s5, s6);
    printf("Test 3: Result: %d (Expected: -1)\n", res3); // Output should be -1

    char *s7 = "example";
    char *s8 = "lm";
    int res4 = any(s7, s8);
    printf("Test 4: Result: %d (Expected: 2)\n", res4); // Output should be 3
}

int any(char *s1, char *s2)
{
    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                return i;
            }
        }
    }

    return -1;
}

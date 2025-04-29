
// Eitercise 5-3. Write a macro for strcpy.

#include <stdio.h>

#define strcpy(dest, src)         \
    do                            \
    {                             \
        char *d = dest, *s = src; \
        while ((*d++ = *s++))     \
            ;                     \
    } while (0)

// ---------------------------------------------------------------------------------
/*
 * EXPLICATION TO WHILE
 * We are using the while loop to copy the string from src to dest
 * The while loop will copy the string from src to dest until it reaches the end of the string
 * the do and while in the macro is used to make the macro a single statement
 * a single statement is required in the if else statement
 */
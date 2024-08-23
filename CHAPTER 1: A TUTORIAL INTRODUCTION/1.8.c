//  Exercise 1-8. Write a program to replace each tab by the three-character sequence >, backspace, -,
//  which prints as >, and each backspace by the similar sequence <.
//  This makes tabs and backspaces visible.
#include <stdio.h>

int main()
{
    int c; // Variable to store the current character

    // Loop until EOF (End Of File) is encountered
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            // Replace tab with ">" followed by backspace and "-"
            putchar('>');
            putchar('\b');
            putchar('-');
        }
        else if (c == '\b')
        {
            // Replace backspace with "<" followed by backspace
            putchar('<');
            putchar('\b');
        }
        else
        {
            // Print all other characters as is
            putchar(c);
        }
    }

    return 0; // Indicate successful program termination
}

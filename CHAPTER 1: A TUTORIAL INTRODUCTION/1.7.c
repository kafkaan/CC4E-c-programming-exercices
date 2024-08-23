#include <stdio.h>

int main()
{
    int c;               // Variable to store the current character read from input
    int lastChar = '\0'; // Initialize lastChar to null character (better readability than 0)

    // Loop until EOF (End Of File) is encountered
    while ((c = getchar()) != EOF)
    {
        // Check if the current character is a blank space
        if (c == ' ')
        {
            // Only print the blank space if the last character was not a blank space
            if (lastChar != ' ')
            {
                putchar(c); // Print a single blank space
            }
            // If the last character was a space, do nothing (skip multiple spaces)
        }
        else
        {
            putchar(c); // Print the current character if it's not a blank space
        }

        lastChar = c; // Update lastChar with the current character
    }

    return 0; // Indicate that the program ended successfully
}

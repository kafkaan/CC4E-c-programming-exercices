#include <stdio.h>

// Program to count the number of newlines, blanks, and tabs in input.

int main()
{
    int c, nl = 0, blank = 0, tab = 0; // Initialize counters to zero

    // Loop until EOF (End Of File) is encountered
    while ((c = getchar()) != EOF)
    {
        // Check if the character is a newline
        if (c == '\n')
        {
            ++nl; // Increment newline counter
        }
        // Check if the character is a blank space
        else if (c == ' ')
        {
            ++blank; // Increment blank space counter
        }
        // Check if the character is a tab
        else if (c == '\t')
        {
            ++tab; // Increment tab counter
        }
    }

    // Print the results
    printf("Newlines: %d\n", nl);
    printf("Blanks: %d\n", blank);
    printf("Tabs: %d\n", tab);

    return 0; // Indicate that the program ended successfully
}

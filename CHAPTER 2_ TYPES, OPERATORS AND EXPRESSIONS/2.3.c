#include <stdio.h>
//Exercise 2-3. Write an alternate version of squeeze(s1, s2) which deletes each character 
//in s1 which matches any character in the string s2.


void squeeze(char *s, char *s2)
{
    int i, j, k;
    int found;

    // Iterate over each character in s
    for (i = j = 0; s[i] != '\0'; i++)
    {
        // Assume the character is not found in s2
        found = 0;

        // Check if the character s[i] is in s2
        for (k = 0; s2[k] != '\0'; k++)
        {
            if (s[i] == s2[k])
            {
                found = 1;
                break; // No need to check further, character is found
            }
        }

        // If the character is not found in s2, include it in the result
        if (!found)
        {
            s[j++] = s[i];
        }
    }

    // Null-terminate the resulting string
    s[j] = '\0';
}

int main(void)
{
    char s1[] = "example";
    char s2[] = "ae";
    squeeze(s1, s2);
    printf("Resulting string: %s\n", s1); // Output should be "xmpl"
    return 0;
}

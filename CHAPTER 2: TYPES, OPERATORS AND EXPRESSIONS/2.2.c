#include <stdio.h>

#define BASE 16

int htoi(char *s, int len);

int main(void)
{
    char hex_string[] = "0x1A3F";
    int len = sizeof(hex_string) / sizeof(hex_string[0]) - 1; // Exclude the null terminator
    int result = htoi(hex_string, len);
    printf("Hexadecimal string: %s\nConverted to integer: %d\n", hex_string, result);
    return 0;
}

int htoi(char *s, int len)
{
    int digit;
    int power = 1; // Initialize power to 1, which represents 16^0
    int result = 0;
    int end_index = 0;

    // Skip the '0x' or '0X' prefix if present
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        end_index = 2;
    }

    // Start from the least significant digit (rightmost) and move left
    for (int i = len - 1; i >= end_index; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            digit = s[i] - '0';
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            digit = s[i] - 'a' + 10;
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            digit = s[i] - 'A' + 10;
        }
        else
        {
            // Invalid character for a hex string
            return -1; // Or handle it in some other way
        }

        result += digit * power;
        power *= BASE; // Increase power for the next digit (moving left)
    }

    return result;
}

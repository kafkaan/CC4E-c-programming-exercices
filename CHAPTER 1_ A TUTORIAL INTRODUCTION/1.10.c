// Exercise 1-10. Write a program which prints the words in its input, one per line.

#include <stdio.h>

#define YES 1
#define NO 0

main()
{
    int c, inword;

    inword = NO;
    while ((c = getchar()) != EOF)
    {
       
        if (c == ' ' || c == '\n' || c == '\t')
            printf("\n");
        else if (inword == NO)
        {
            inword = YES;
            putchar(c);
            
        }
        else if(inword == YES)
        {
            putchar(c);
        }
    }
   
}
/*
 * Exercise 4-4. Write a routine ungets(s) which will push back an entire string onto the input.
 * Should ungets know about buf and bufp, or should it just use ungetch?
 */

extern int getch(void);
extern void ungetch(int);

void ungets(char s[])
{
    int i = 0;

    while (s[i] != '\0')
    {
        ungetch(s[i]);
        i++;
    }
}
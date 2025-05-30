void itoa(char s[],int n)    
/* convert n to characters in s */
{
    int i, sign;

    if ((sign = n) < 0)    /* record sign */
        n = -n;              /* make n positive */
    i = 0;
    do {    /* generate digits in reverse order */
        s[i++] = n % 10 + '0';     /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    
    if (sign < 0)
        s[i++] = '-';

    s[i] = '\\0';

    //reverse
    reverse(s);
}
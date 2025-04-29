
/* compte les bits à 1 dans n */
int bitcount(unsigned n) 
{
    int b;

    for (b = 0; n != 0; n >>= 1)
        if (n & 01)
            b++;
    return(b);
}


void main(void)
{
    // declare variables
    unsigned int n;
    int b;

    // read string from uuser
    printf("Enter a number: ");
    // scanf is used to read a number
    // from the user
    // it reads until a newline or EOF
    
    scanf("%u", &n);

    // convert string to integeru
    b = bitcount(n);

    // print the result
    printf("The number of bits set to 1 in %u is: %d\n", n, b);
}

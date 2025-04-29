
// atoi: convert string s to integer
int atoi(char s[]) {
    // declare variables integer n
    int i, n;

    // skip white space
    for (i = 0; s[i] == ' ' || s[i] == '\n' || s[i] == '\t'; ++i)
        ;   // skip white space
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + s[i] - '0';
    return(n);
}

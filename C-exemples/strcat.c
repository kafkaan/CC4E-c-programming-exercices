void strcat(char s[], char t[]) {
    // declare i and j
    int i, j;
    // initialize i and j to 0
    i = j = 0;
    // find end of s
    while (s[i] != '\0')  /* find end of s */
        i++;
    // copy t to end of s
    while ((s[i++] = t[j++]) != '\0') /* copy t */
        ;
}

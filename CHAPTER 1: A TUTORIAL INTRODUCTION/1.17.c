#include <stdio.h>

#define MAXLINE 1000 /* Maximum line size */

/* Function prototypes */
int get_line(char s[], int lim);
void reverse(char s[], int len);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        reverse(line, len - 1); /* Exclude newline character from length */
        printf("%s", line);
    }

    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* reverse: reverse the string s of length len */
void reverse(char s[], int len) {
    int i, j;
    char temp;

    for (i = 0, j = len; i < j; ++i, --j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

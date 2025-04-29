#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int main() {
    char line[MAXLINE], lastLine[MAXLINE];

    lastLine[0] = '\0'; // Initialize lastLine to an empty string

    while (fgets(line, MAXLINE, stdin) != NULL) {
        if (strcmp(line, lastLine) != 0) {
            printf("%s", line);
            strcpy(lastLine, line);
        }
    }

    return 0;
}
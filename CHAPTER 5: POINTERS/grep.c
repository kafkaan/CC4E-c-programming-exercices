#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

main(int argc, char *argv[]) /* find pattern from first argument */

{
    char line[MAXLINE];

    if (argc != 2)
        printf("Usage: find pattern\\n");
    else
        while (getline(line, MAXLINE) > 0)
            if (index(line, argv[1]) >= 0)
                printf("%s", line);
}
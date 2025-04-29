#include <stdio.h>
#include <string.h>

main(int argc, char *argv[]) /* echo arguments; 1st version */
{
    int i;

    for (i = 1; i < argc; i++)
        printf("%s%c", argv[i], (i < argc - 1) ? ' ' : '\n');
}

// -------------------------------------------------------
main(int argc, char *argv[]) /* echo arguments; 2nd version */
{
    while (--argc > 0)
        printf("%s%c", *++argv, (argc > 1) ? ' ' : '\n');
}

// -------------------------------------------------------
main(int argc, char *argv[]) /* echo arguments; 3rd version */
{
    while (--argc > 0)
        printf((argc > 1) ? "%s " : "%s\n", *++argv);
}
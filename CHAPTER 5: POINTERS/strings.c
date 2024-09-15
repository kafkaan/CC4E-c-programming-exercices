strcpy(s, t) /* copy t to s */
    char s[],
    t[];
{
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\\0')
        i++;
}

// ---------------------------------------------------

strcpy(s, t) /* copy t to s; pointer version 1 */
    char *s,
    *t;
{
    while ((*s = *t) != '\0')
    {
        s++;
        t++;
    }
}

// ---------------------------------------------------
strcpy(s, t) /* copy t to s; pointer version 1 */
    char *s,
    *t;
{
    while ((*s = *t) != '\0')
    {
        s++;
        t++;
    }
}

// ---------------------------------------------------
strcpy(s, t) /* copy t to s; pointer version 2 */
    char *s,
    *t;
{
    while ((*s++ = *t++) != '\0')
        ;
}

// --   -------------------------------------------------

strcmp(char s[], char t[]) /* return <0 if s<t, 0 if s==t, >0 if s>t */
{
    int i;

    i = 0;

    while (s[i] == t[i])
        if (s[i++] == '\0')
            return (0);
    return (s[i] - t[i]);
}

// ---------------------------------------------------

strcmp( char *s,char *t) /* return <0 if s<t, 0 if s==t, >0 if s>t */
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return (0);
    return (*s - *t);
}

// ---------------------------------------------------

#include <stdlib.h>

char *strsave(s) /* sauvegarde de la chaîne s quelque part */
char *s;
{
    char *p, *alloc();

    if ((p = alloc(strlen(s) + 1)) != NULL)
        strcpy(p, s);
    return (p);
}

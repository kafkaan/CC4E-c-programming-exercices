#include <stdio.h>
#define NULL 0         /* pointer value for error report */
#define ALLOCSIZE 1000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

// ici on cree un variable pointeur au lieu d avoir une constante de pointeur

char *alloc(n) /* return pointer to n characters */
int n;
{
    if (allocp + n <= allocbuf + ALLOCSIZE)
    { /* fits */
        allocp += n;
        return (allocp - n); /* old p */
    }
    else /* not enough room */
        return (NULL);
}

free(p) /* free storage pointed to by p */
    char *p;
{
    // si p est superieur a allocbuf donc si on a deja ajoute des elements dans la pile alors nouvelle pointeur du pile
    // a l'adresse de p
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
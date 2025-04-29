#include <stdlib.h>
#include <string.h>

struct nlist
{ /* entrée de table de base */
    char *name;
    char *def;
    struct nlist *next; /* entrée suivante dans la chaîne */
};

#define HASHSIZE 100
static struct nlist *hashtab[HASHSIZE]; /* tableau de pointeurs */

#define HASHSIZE 100

int hash(char *s) /* former la valeur de hachage pour la chaîne s */
{
    int hashval;

    for (hashval = 0; *s != '\0';)
        hashval += *s++;
    return (hashval % HASHSIZE);
}

struct nlist *lookup(s) /* chercher s dans hashtab */
char *s;
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return (np); /* trouvé */
    return (NULL);       /* non trouvé */
}

struct nlist *install(name, def) /* mettre (name, def) */
char *name, *def;                /* dans hashtab */
{
    struct nlist *np, *lookup();
    char *strsave(), *alloc();
    int hashval;
    if ((np = lookup(name)) == NULL)
    { /* non trouvé */
        np = (struct nlist *)alloc(sizeof(*np));
        if (np == NULL)
            return (NULL);
        if ((np->name = strsave(name)) == NULL)
            return (NULL);
        hashval = hash(np->name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else               /* déjà là */
        free(np->def); /* libérer la définition précédente */
    if ((np->def = strsave(def)) == NULL)
        return (NULL);
    return (np);
}
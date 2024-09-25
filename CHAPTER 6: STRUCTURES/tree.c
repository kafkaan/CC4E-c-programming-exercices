#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ------------------------------------------------------------------------------------------

#define MAXWORD 20
#define LETTER 'a'

// ----------------------------------------------------------------------------------------

struct tnode *tree(struct tnode *p, char *w);
char *strsave(char *s);
int getword(char *w, int lim);
void treeprint(struct tnode *p);

// --------------------------------------------------------------------------------------------

// STRUCTURE TREE
struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

// ----------------------------------------------------------------------------------------
int main(void)
{
    struct tnode *root;
    char word[MAXWORD];
    int t;

    root = NULL;
    while ((t = getword(word, MAXWORD)) != EOF)
    {
        if (t == LETTER)
        {
            root = tree(root, word);
        }
    }

    treeprint(root);
    return 0;
}

// ---------------------------- Tree func ---------------------------------------
struct tnode *tree(struct tnode *p, char *w)
{
    int cond;
    if (p == NULL)
    {
        p = (struct tnode *)malloc(sizeof(struct tnode));
        p->word = strsave(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
    {
        p->count++;
    }
    else if (cond < 0)
    {
        p->left = tree(p->left, w);
    }

    else
    {
        p->right = tree(p->right, w);
    }

    return (p);
}


// -------------------------------------------------------------- STRINGS ---------------------------
char *strsave(char *s) /* sauvegarde de la chaîne s quelque part */
{
    char *p;

    if ((p = malloc(strlen(s) + 1)) != NULL)
        strcpy(p, s);
    return (p);
}

int getword(char *w, int lim) /* get next word from input */
{
    int c, t;
    if (!isalpha(c = *w++ = getchar()))
    {
        *w = '\0';
        return (c);
    }

    while (--lim > 0)
    {
        t = isalnum(c = *w++ = getchar());
        if (!t)
        {
            break;
        }
    }
    *(w - 1) = '\0';
    return (LETTER);
}


// ---------------------------- Tree print ---------------------------------


void treeprint(struct tnode *p) /* print tree p recursively */

{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}
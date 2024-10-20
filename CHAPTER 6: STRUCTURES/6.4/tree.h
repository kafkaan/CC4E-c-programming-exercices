// tree.h

#ifndef TREE_H
#define TREE_H

#include "stack.h"

#define MAXWORD 20


// ---------------------------- Structure pour un nœud de la pile ----------------------------

typedef struct tnode
{
    PPILE stack;
    struct tnode *left;
    struct tnode *right;
} TREE, *PTREE;

// ---------------------- Prototypes des fonctions -----------------------------------

PTREE addtree(PTREE p, char *w);
void treeprint(PTREE p);
char *strsave(char *s);
int getword(char *w, int lim);
int getch(void);
void ungetch(int c);

#endif

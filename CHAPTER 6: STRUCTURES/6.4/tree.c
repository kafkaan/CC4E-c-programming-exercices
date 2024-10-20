// tree.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#include "stack.h"

#define BUFSIZE 100

static char buf[BUFSIZE];
int bufp = 0;

/* -------------------------------------------------------------------------- */

PTREE addtree(PTREE p, char *w)
{
    int cond;

    if (p == NULL)
    {
        p = (PTREE)malloc(sizeof(TREE));
        char *word_to_push = strsave(w);
        printf("Word to push in pile : %s \n", word_to_push);
        PPILE new_stack = newNode(word_to_push);
        p->stack = new_stack;
        p->left = p->right = NULL;
    }
    else if ((cond = strncmp(peek(p->stack), w, 7)) == 0)
    {
        printf("Mot au sommet de la pile : %s \n", peek(p->stack));
        char *word_to_push = strsave(w);
        printf("Word to push in pile : %s \n", word_to_push);
        push(&(p->stack), word_to_push);
    }
    else if (cond < 0)
    {
        p->left = addtree(p->left, w);
    }
    else
    {
        p->right = addtree(p->right, w);
    }

    return p;
}

/* ------------------------------------------------------------------------------------------------------- */

/// @brief Print the tree left middle rigth sens
/// @param p
void treeprint(PTREE p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        while (!isEmpty(p->stack))
        {
            char *word = pop(&(p->stack));
            printf("%s\n", word);
        }
        treeprint(p->right);
    }
}

/* --------------------------------------------------------------------------------------------------------- */

/// @brief Function to stock a word in the memory
/// @param s
/// @return the word
char *strsave(char *s)
{
    char *p = malloc(strlen(s) + 1);
    if (p != NULL)
    {
        strcpy(p, s);
    }
    return p;
}

/* ---------------------------------------------------------------------------------------------------------------*/

/// @brief Function to get next word
/// @param w
/// @param lim
/// @return EOF or the special caracter if no word or LETTER
int getword(char *w, int lim)
{
    int c;
    char *w_start = w;

    while (isspace(c = getch()))
        ;

    if (c == EOF)
    {
        return EOF;
    }

    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }

    *w++ = c;

    while (--lim > 0)
    {
        c = getch();
        if (!isalnum(c))
        {
            ungetch(c);
            break;
        }
        *w++ = c;
    }

    *w = '\0';
    return w_start[0];
}

/// @brief Funtion to get back indesirable letters
/// @param  void
/// @return letter
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/// @brief Function to stock indesirable letter
/// @param c
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: trop de caractères\n");
    else
        buf[bufp++] = c;
}

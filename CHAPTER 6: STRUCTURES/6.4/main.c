// main.c

#include "tree.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

static char *keyword[] = {
    "auto",
    "break",
    "case",
    "char",
    "const",
    "continue",
    "default",
    "do",
    "double",
    "else",
    "enum",
    "extern",
    "float",
    "for",
    "goto",
    "if",
    "int",
    "long",
    "register",
    "restrict",
    "return",
    "short",
    "signed",
    "sizeof",
    "static",
    "struct",
    "switch",
    "typedef",
    "union",
    "unsigned",
    "void",
    "volatile",
    "while"};

#define NWORDS (sizeof(keyword) / sizeof(keyword[0]))

int binary(char *word, char *keyword[], int n);

/* ---------------------------------------------------------------------------------------------------------------------*/

int main()
{
    PTREE root = NULL;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]) && binary(word, keyword, NWORDS) == -1) // Ajouter seulement si le mot est valide
        {
            root = addtree(root, word);
        }
    }

    treeprint(root);
    return 0;
}

/* ---------------------------------------------------------------------------------------------------------------------*/

int binary(char *word, char *keyword[], int n)
{
    int low = 0, high = n - 1, mid, cond;

    while (low <= high)
    {
        mid = (low + high) / 2;
        cond = strcmp(word, keyword[mid]);
        if (cond < 0)
        {
            high = mid - 1;
        }
        else if (cond > 0)
        {
            low = mid + 1;
        }
        else
        {
            return mid; // Mot trouvé
        }
    }
    return -1;
}
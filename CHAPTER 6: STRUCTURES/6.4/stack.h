// stack.h
#ifndef STACK_H
#define STACK_H

#define MAX_WORD_LENGTH 100

// ---------------------------- Structure pour un nœud de la pile ----------------------------

typedef struct StackNode
{
    char word[MAX_WORD_LENGTH];
    struct StackNode *next;
} PILE, *PPILE;

// ------------------------------- Prototypes des fonctions ---------------------------------------

PPILE newNode(char *word);
int isEmpty(PPILE root);
void push(PPILE *root, char *word);
char *pop(PPILE *root);
char *peek(PPILE root);

#endif

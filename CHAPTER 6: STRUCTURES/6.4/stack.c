// stack.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "tree.h"

/*  --------------------------------------------------------------------------------------------------------  */

/// @brief Function to stock a word in the memory and create a stack node
/// @param word 
/// @return 
PPILE newNode(char *word)
{
    PPILE stackNode = (PPILE)malloc(sizeof(struct StackNode));
    strcpy(stackNode->word, word);
    stackNode->next = NULL;
    return stackNode;
}

/*  --------------------------------------------------------------------------------------------------------  */

/// @brief Function to check if the stack is empty
/// @param root
/// @return true if the stack is empty else false
int isEmpty(PPILE root)
{
    return !root;
}

/*  --------------------------------------------------------------------------------------------------------  */

/// @brief Function to push a word in the stack
/// @param root 
/// @param word 
void push(PPILE *root, char *word)
{
    PPILE stackNode = newNode(word);
    stackNode->next = *root;
    *root = stackNode;
    printf("%s pushed to stack\n", word);
}

/*  --------------------------------------------------------------------------------------------------------  */

/// @brief Function to pop a word from the stack
/// @param root 
/// @return the word or NULL if the stack is empty
char *pop(PPILE *root)
{
    if (isEmpty(*root))
        return NULL;

    struct StackNode *temp = *root;
    *root = (*root)->next;

    // Dupliquer le mot avant de libérer le nœud
    char *popped = strsave(temp->word);
    free(temp); // Libérer le nœud

    return popped; // Retourner la copie du mot
}

/*  --------------------------------------------------------------------------------------------------------  */

/// @brief Function to get the word at the top of the stack
/// @param root 
/// @return 
char *peek(PPILE root)
{
    if (isEmpty(root))
        return NULL;
    return root->word;
}

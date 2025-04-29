#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

struct lnode
{                       /* Une ligne de texte */
    char *text;         /* pointe vers le texte */
    struct lnode *prev; /* La ligne précédente */
    struct lnode *next; /* La ligne suivante */
};

int main() /* imprimer les lignes en ordre inverse */
{
    struct lnode *head = NULL;
    struct lnode *tail = NULL;
    struct lnode *current;
    char line[MAXLINE];

    while (fgets(line, MAXLINE, stdin) != NULL)
    {
        char *save = (char *)malloc(strlen(line) + 1);
        strcpy(save, line);

        struct lnode *new = (struct lnode *)malloc(sizeof(struct lnode));
        new->text = save;
        new->next = NULL;
        new->prev = tail;

        if (head == NULL)
            head = new;

        if (tail != NULL)
            tail->next = new;
        tail = new;
    }

    for (current = tail; current != NULL; current = current->prev)
    {
        printf("%s", current->text);
    }
}
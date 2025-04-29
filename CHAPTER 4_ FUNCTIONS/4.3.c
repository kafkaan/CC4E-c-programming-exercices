#include <stdio.h>
#include <stdlib.h> // for atof

#define BUFSIZE 100 // buffer for ungetch
#define MAXOP 20    // max size of operand or operator
#define NUMBER '0'  // signal that a number was found
#define TOOBIG '9'  // signal that the number is too big

extern int getop(char[], int lim); // get next operator or numeric operand
extern double push(double);        // push f onto value stack
extern double pop(void);           // pop and return top value from stack

extern int sp;       // pointer to the next free stack position
extern double val[]; // stack

extern void clear();      // clear the stack
extern int getch(void);   // get a (possibly pushed-back) character
extern void ungetch(int c); // push character back on input

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s, MAXOP)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            printf("pushing %s\n", s);
            push(atof(s));
            break;
        case '+':
            printf("adding %f and %f\n", val[sp - 1], val[sp - 2]);
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push((int)pop() % (int)op2);
            else
                printf("error: zero divisor\n");
            break;
        case '=':
            printf("result: ");
            printf("\t%.8g\n", pop());
            break;
        case TOOBIG:
            printf("error: number too big\n");
            break;
        case 'c':
            printf("clearing the stack\n");
            clear();
            break;
        case 'e':
            printf("erasing the last value of the stack\n");
            erase();
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

void erase(void)
{
    if (sp > 0)
        --sp;
    else
        printf("error: stack empty\n");
}

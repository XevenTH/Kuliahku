#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_VALUE 100

typedef struct
{
    char data[MAX_VALUE];
    int top;
} Stack;

void Init(Stack *s)
{
    s->top = -1;
}

bool isEmpty(Stack *s)
{
    return s->top == -1;
}

bool IsFull(Stack *s)
{
    return s->top == MAX_VALUE - 1;
}

void Push(Stack *s, char val)
{
    if (IsFull(s))
    {
        printf("Stack overflow\n");
        exit(1);
    }

    s->top++;
    s->data[s->top] = val;
}

char Pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack under flow\n");
        exit(1);
    }

    char c = s->data[s->top];
    s->top--;

    return c;
}

int SymbolChecker(char symbol)
{
    if (symbol == '^')
    {
        return 3;
    }
    else if (symbol == '*' || symbol == '/')
    {
        return 2;
    }
    else if (symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ConvertToPostFix(Stack *s,char *infix, char *postfix)
{
    int i = 0, j = 0;
    char symbol;

    while ((symbol = infix[i++]) != '\0')
    {
        if (symbol == '(')
        {
            Push(s, symbol);
        }
        else if (isalnum(symbol))
        {
            postfix[j++] = symbol;
        }
        else if (symbol == ')')
        {
            while (s->data[s->top] != '(')
            {
                postfix[j++] = Pop(s);
            }

            Pop(s);
        }
        else
        {
            while (SymbolChecker(s->data[s->top]) >= SymbolChecker(symbol))
            {
                postfix[j++] = Pop(s);
            }

            Push(s, symbol);
        }
    }

    while (s->top != -1)
    {
        postfix[j++] = Pop(s);
    }

    postfix[j] = '\0';
}

int main()
{
    Stack newStack;
    Init(&newStack);

    char infix[MAX_VALUE], postfix[MAX_VALUE];

    printf("Masukan Infix (Tanpa Spasi!!!) : ");
    scanf("%s", &infix);

    ConvertToPostFix(&newStack, infix, postfix);

    printf("Postfix Dari Infix \"%s\" Adalah : %s", infix, postfix);
    return 0;
}
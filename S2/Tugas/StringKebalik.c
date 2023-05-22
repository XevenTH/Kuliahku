#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct
{
    char data[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int IsFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char c)
{
    if (IsFull(s))
    {
        printf("Stack overflow\n");
        exit(1);
    }
    s->top++;
    s->data[s->top] = c;
}

char pop(Stack *s)
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

void reverseString(char *str)
{
    Stack s;
    int len = strlen(str);
    init(&s);
    for (int i = 0; i < len; i++)
    {
        push(&s, str[i]);
    }
    for (int i = 0; i < len; i++)
    {
        str[i] = pop(&s);
    }
}

int main()
{
    char str[MAX_SIZE];
    printf("Input string: ");
    scanf("%s", str);
    reverseString(str);
    printf("Output: %s\n", str);
    return 0;
}
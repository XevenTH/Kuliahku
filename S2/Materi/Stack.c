#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

typedef struct stack
{
    int Datas[MAX_SIZE];
    int Top;
} Stack;

void CreateStack(Stack *stack)
{
    return stack->Top = -1;
}

bool IsEmpty(Stack *stack)
{
    return stack->Top == -1;
}

bool IsFull(Stack *stack)
{
    return stack->Top == MAX_SIZE;
}

int Peek(Stack *stack)
{
    if (IsEmpty(stack))
        return -1;

    return stack->Datas[stack->Top];
}

void Push(Stack *stack, int val)
{
    if (IsFull)
    {
        printf("Stack Sudah Full....");
        return;
    }

    stack->Top++;
    stack->Datas[stack->Top] = val;
    printf("Value Berhasil Ditambahkan....");
}

void Pop(Stack *stack)
{
    if (IsEmpty(stack))
    {
        printf("Stack Masih Kosong...");
        return;
    }

    stack->Top--;
    printf("Value Terakhir Berhasil Dihapus....");
}

void PrintStack(Stack *stack)
{
    if (IsEmpty(stack))
    {
        printf("Stack Masih Kosong....");
        return;
    }

    for (int i = stack->Top; i >= 0; i--)
    {
        printf("%d ", stack->Datas[i]);
    }
}

int main()
{
    Stack newStack;

    CreateStack(&newStack);

    return 0;
}

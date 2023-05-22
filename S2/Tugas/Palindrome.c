#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char data[25];
    int top;
} StrStruct;

void Init(StrStruct *s)
{
    s->top = -1;
}

int IsEmpty(StrStruct *s)
{
    return s->top == -1;
}

int IsFull(StrStruct *s)
{
    return s->top == 25 - 1;
}

void Push(StrStruct *s, char c)
{
    if (IsFull(s))
    {
        printf("StrStruct overflow\n");
        exit(1);
    }
    s->top++;
    s->data[s->top] = c;
}

char Pop(StrStruct *s)
{
    if (IsEmpty(s))
    {
        printf("Stack underflow\n");
        exit(1);
    }
    char c = s->data[s->top];
    s->top--;
    return c;
}

void PalindromeCheck(char *inputStr)
{
    StrStruct newString;
    
    int length = strlen(inputStr);
    char reverseString[length];

    Init(&newString);

    for (int i = 0; i < length; i++)
    {
        Push(&newString, inputStr[i]);
    }
    for (int i = 0; i < length; i++)
    {
        reverseString[i] = Pop(&newString);
    }

    if (strcmp(newString.data, reverseString))
    {
        printf("%s Is Not Palindrome", newString.data);
    }
    else
    {
        printf("%s Is Palindrome", newString.data);
    }
    

    printf("\nOutput : %s", reverseString);
}

int main()
{
    char inputStr[25];

    printf("Masukan Kata : ");
    scanf("%s", &inputStr);

    PalindromeCheck(inputStr);

    return 0;
}

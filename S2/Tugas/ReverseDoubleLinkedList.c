#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *Create(Node *head)
{
    Node *newNode = malloc(sizeof(Node));

    printf("Masukan Angka: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

Node *Last(Node *head)
{
    Node *newNode = Create(head);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = newNode;
        newNode->prev = tmp;
        newNode->next = NULL;
    }

    return head;
}

int main()
{
    return 0;
}

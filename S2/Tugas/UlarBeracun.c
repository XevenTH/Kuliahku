#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    char data;
    struct node *next;
} Node;

Node *Create()
{
    Node *newNode = malloc(sizeof(Node));

    printf("Beracun Atau Tidak (T/B): ");
    scanf(" %c", &newNode->data);

    newNode->next = NULL;

    return newNode;
}

Node *Last(Node *head)
{
    Node *newNode = Create();

    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }

        tail->next = newNode;
        newNode->next = head;
    }

    return head;
}

Node *DeleteLast(Node *head)
{
    if (head == NULL)
    {
        printf("\n SImpul Sedang Kosong \n");
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *beforeLast = head;
        while (beforeLast->next->next != head)
        {
            beforeLast = beforeLast->next;
        }


        Node *tmp = beforeLast->next;

        beforeLast->next = head;
        free(tmp);
        
        if (beforeLast->data == 'b')
            return NULL;
            
    }

    return head;
}

void Print(Node *head)
{
    if (head == NULL)
    {
        printf("\nSimpul Sedang Kosong\n");
    }
    else
    {
        Node *tail = head;
        while (tail->next != head)
        {
            printf("[%c] ", tail->data);
            tail = tail->next;
        }

        printf("[%c] \n", tail->data);
    }
}

void EatTails(Node *head)
{
    int tail;
    printf("Berapa Tail: ");
    scanf("%d", &tail);

    for (int i = 0; i < tail; i++)
    {
        head = Last(head);
    }

    Print(head);

    for (int i = tail; i > 0; i--)
    {
        head = DeleteLast(head);
        if (head == NULL)
        {
            printf("\nUlar Mati Setelah Memakan Ekor Sebanyak %d Kali", i);
            break;
        }
    }
}

int main()
{
    Node *head = NULL;

    EatTails(head);

    return 0;
}

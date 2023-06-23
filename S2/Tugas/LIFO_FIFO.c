#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *Create(int val)
{
    Node *newNode = malloc(sizeof(Node));

    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

Node *First(Node *head, Node *newNode)
{
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    return head;
}

Node *Last(Node *head, Node *newNode)
{
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
    }

    return head;
}

void Print(Node *head)
{
    if (head == NULL)
    {
        printf("Data Tidak Ada\n");
        return;
    }

    while (head != NULL && head->next != NULL)
    {
        printf("[%d] ", head->data);
        head = head->next;
    }

    printf("[%d] \n", head->data);
}

int main()
{
    Node *headFifo = NULL, *headLifo = NULL;
    char pilihan;

    do
    {
        int bil = 0;

        printf("Masukan Bilangan: ");
        scanf("%d", &bil);

        Node *newNodeFifo = Create(bil);
        Node *newNodeLifo = Create(bil);

        headLifo = First(headLifo, newNodeLifo);
        headFifo = Last(headFifo, newNodeFifo);

        printf("Ada Data Lagi(y/t): ");
        scanf(" %c", &pilihan);

    } while (pilihan == 'y');

    printf("\nBilangan Yang Di Masukan Dengan LIFO: \n");
    Print(headLifo);
    printf("Bilangan Yang Di Masukan Dengan FIFO: \n");
    Print(headFifo);

    return 0;
}

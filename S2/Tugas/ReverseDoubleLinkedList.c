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

Node *Create(int val)
{
    Node *newNode = malloc(sizeof(Node));

    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

Node *Last(Node *head)
{
    int val;

    printf("Masukan Angka: ");
    scanf("%d", &val);

    Node *newNode = Create(val);
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

Node  *Reverse(Node *head, Node *reverseHead)
{
    Node *Indexer = head;
    while (Indexer->next != NULL)
    {
        Indexer = Indexer->next;
    }

    do
    {
        Node *newNode = Create(Indexer->data);

        if (reverseHead == NULL)
        {
            reverseHead = newNode;
        }
        else
        {
            Node *tmp = reverseHead;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }

            tmp->next = newNode;
            newNode->prev = tmp;
            newNode->next = NULL;
        }

        Indexer = Indexer->prev;
    } while (Indexer != NULL);

    return reverseHead;
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
    Node *head = NULL;
    Node *reverseHead = NULL;
    char pilihan;

    do
    {
        head = Last(head);

        printf("Ada Data Lagi(y/t): ");
        scanf(" %c", &pilihan);
    } while (pilihan == 'y');

    reverseHead = Reverse(head, reverseHead);

    printf("\nStack Sebelum Di Reverse: ");
    Print(head);
    printf("\n");
    printf("Stack Sesudah Di Reverse: ");
    Print(reverseHead);

    return 0;
}

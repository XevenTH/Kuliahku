#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
    struct node *prev;
} Node;

Node *Create(int isi)
{
    Node *p = malloc(sizeof(Node));
    p->info = isi;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

Node *Last(Node *head)
{
    int val = 0;

    printf("Masukan Angka: ");
    scanf("%d", &val);

    Node *p = Create(val);

    if (head == NULL)
    {
        p->next = p;
        p->prev = p;
        head = p;
    }
    else
    {
        p->next = head;
        p->prev = head->prev;
        head->prev->next = p;
        head->prev = p;
    }

    return head;
}

Node *Reverse(Node *head)
{
    if (head == NULL)
    {
        printf("List Sedang Kosong");
        return head;
    }

    
    Node *tail = head->prev;
    Node *indexer = head->prev;
    do
    {
        Node *temp = indexer->prev;
        indexer->prev = indexer->next;
        indexer->next = temp;

        indexer = temp;
    } while (indexer != tail);

    head = tail;
    return head;
}

void Print(Node *head)
{
    printf("Isi List : ");

    if (head == NULL)
    {
        printf("[]");
    }
    else
    {
        Node *current = head;
        do
        {
            printf("[%d] ", current->info);
            current = current->next;
        } while (current != head);

        printf("\n");
    }
}

int main()
{
    Node *head = NULL;
    char choice = 'y';

    while (choice != 'n')
    {
        head = Last(head);
        printf("Lagi (y/n): ");
        scanf(" %c", &choice);
        system("cls");
    }

    Print(head);
    head = Reverse(head);
    printf("----Setelah Di Reverse----\n");
    Print(head);

    return 0;
}

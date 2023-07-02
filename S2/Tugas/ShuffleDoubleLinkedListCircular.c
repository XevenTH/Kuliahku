#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int Size(Node *head)
{
    int size = 0;
    Node *temp = head;
    do
    {
        temp = temp->next;
        size++;
    } while (temp != head);

    return size;
}

Node *Finder(Node *head, int cycle)
{
    Node *temp = head;
    for (int i = 1; i < cycle; i++)
    {
        temp = temp->next;
    }

    return temp;
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
        Node *curent = head;
        do
        {
            printf("[%d] ", curent->info);
            curent = curent->next;
        } while (curent != head);
    }
}

void Swap(Node *a, Node *b)
{
    if (a == b)
        return;
    Node *ap = a->prev, *an = a->next;
    Node *bp = b->prev, *bn = b->next;
    if (an == b)
    {
        a->next = bn;
        a->prev = b;
        b->next = a;
        b->prev = ap;
        ap->next = b;
        bn->prev = a;
    }
    else if (bn == a)
    {
        a->next = b;
        a->prev = bp;
        b->next = an;
        b->prev = a;
        bp->next = a;
        an->prev = b;
    }
    else
    {
        a->next = bn;
        a->prev = bp;
        b->next = an;
        b->prev = ap;
        ap->next = b;
        an->prev = b;
        bp->next = a;
        bn->prev = a;
    }
}

Node *Shuffle(Node *head)
{
    int size = Size(head);

    srand(time(0));
    for (int i = 1; i <= size; i++)
    {
        int num = rand() % size + 1;

        Node *temp = Finder(head, num);

        switch (num)
        {
        case 1:
            head = temp->next;
            break;
        case 4:
            head = temp;
            break;
        }

        Swap(temp, temp->next);
    }

    return head;
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
    head = Shuffle(head);
    printf("\nSesudah di acak: \n");
    Print(head);
}
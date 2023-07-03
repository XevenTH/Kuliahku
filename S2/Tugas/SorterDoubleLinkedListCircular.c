#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

Node *Finder(Node *head, int cycle)
{
    Node *temp = head;
    for (int i = 1; i < cycle; i++)
    {
        temp = temp->next;
    }

    return temp;
}

void Swap(Node *a, Node *b)
{
    if (a == b)
        return;
    Node *ap = a->prev, *an = a->next;
    Node *bp = b->prev, *bn = b->next;

    // Jika b Berada Disebelah Kana a
    if (an == b)
    {
        a->next = bn;
        a->prev = b;
        b->next = a;
        b->prev = ap;
        ap->next = b;
        bn->prev = a;
    }
    // Jika b Merupakan Tail dan A Merupakan Head
    else if (bn == a)
    {
        a->next = b;
        a->prev = bp;
        b->next = an;
        b->prev = a;
        bp->next = a;
        an->prev = b;
    }
    // Jika b Dan a Bersebrangan
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

// Sorint Menggunakan Algoritma Selection Sort
Node *Sort(Node *head)
{
    if (head == NULL)
    {
        printf("List Sedang Kosong");
        return head;
    }

    // Menyiapkan Beberapa Variabel tambahan Untuk Looping
    Node *current = head, *indexer = head->next, *tempH = head;

    // Dikarenakan Susahnya Memmaintain Address Memory Untuk Melakukan Cycle Dalam List, Kita Mengakalinya Dengan Cara Membuat Beberapa Variabel Untuk Mencari Starting Node Dan Indexer
    int limiter = 0, currentCycle = 1, indexerCycle = 1;

    // Untuk menunjuk current
    do
    {
        Node *min = Finder(head, currentCycle);

        // untuk menunjuk indexer yang digunakan untuk mengecek
        while (indexerCycle <= Size(head))
        {
            bool checker = indexer->info < min->info;
            if (checker)
            {
                min = indexer;
                // Cek Apakah Program Telah Menukar Head
                if (current == head)
                    tempH = min;
            }
            indexer = Finder(head, ++indexerCycle);
        }

        if(head != tempH) head = tempH;
        // Swap Node
        Swap(current, min);

        // Reset Cycle
        current = Finder(head, ++currentCycle);
        indexer = Finder(head, currentCycle + 1);
        indexerCycle = currentCycle + 1;
    } while (currentCycle != Size(head));

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
    head = Sort(head);
    printf("----Sesudah di Sort---- \n");
    Print(head);

    return 0;
}

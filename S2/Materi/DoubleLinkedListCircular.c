#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elemen *address;

struct elemen
{
    int info;
    address next;
    address prev;
};

typedef struct
{
    address first;
    address last;
} ListInt;

void CreateList(ListInt *l)
{
    l->first = NULL;
    l->last = NULL;
}

address Create(int isi)
{
    address p = (address)malloc(sizeof(struct elemen));
    p->info = isi;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void First(ListInt *l, address p)
{
    if ((l->first == NULL) && (l->last == NULL))
    {
        l->first = p;
        l->last = p;
        p->next = l->first;
        p->prev = l->last;
    }
    else
    {
        p->next = l->first;
        l->first->prev = p;
        l->first = p;
        l->first->prev = l->last;
        l->last->next = l->first;
    }
}

void Last(ListInt *l, address p)
{
    if ((l->first == NULL) && (l->last == NULL))
    {
        l->first = p;
        l->last = p;
        p->next = l->first;
        p->prev = l->last;
    }
    else
    {
        p->prev = l->last;
        l->last->next = p;
        l->last = p;
        l->first->prev = l->last;
        l->last->next = l->first;
    }
}

void InsertAfter(ListInt *l, address p, int cari)
{
    if ((l->first == NULL) && (l->last == NULL))
    {
        l->first = p;
        l->last = p;
        p->next = l->first;
        p->prev = l->last;
    }
    else
    {
        address q = l->first;
        while ((q->next != NULL) && (q->info != cari))
        {
            q = q->next;
        }
        if (q->info == cari)
        {
            p->next = q->next;
            p->prev = q;
            q->next->prev = p;
            q->next = p;
        }
    }
}

void DeleteFirst(ListInt *l, address p)
{
    p = l->first;
    if ((l->first != NULL) && (l->last != NULL))
    {
        if (l->first == l->last)
        {
            l->first = NULL;
            l->last = NULL;
            p->next = NULL;
            p->prev = NULL;
        }
        else
        {
            l->first = p->next;
            l->first->prev = l->last;
            l->last->next = l->first;
        }
    }
}

void DeleteLast(ListInt *l, address p)
{
    p = l->last;
    if ((l->first != NULL) && (l->last != NULL))
    {
        if (l->first == l->last)
        {
            l->first = NULL;
            l->last = NULL;
            p->next = NULL;
            p->prev = NULL;
        }
        else
        {
            l->last = p->prev;
            l->last->next = l->first;
        }
    }
}

void Delete(ListInt *l, address p, int cari)
{
    p = l->first;
    if ((l->first != NULL) && (l->last != NULL))
    {
        if ((l->first == l->last) && (l->first->info == cari))
        {
            l->first = NULL;
            l->last = NULL;
            p->next = NULL;
            p->prev = NULL;
        }
        else
        {
            address q;
            while ((p->next != NULL) && (p->info != cari))
            {
                q = p;
                p = p->next;
            }
            if (p->info == cari)
            {
                if (p == l->first)
                {
                    DeleteFirst(l, p);
                }
                else if (p == l->last)
                {
                    DeleteLast(l, p);
                }
                else
                {
                    q->next = p->next;
                    p->next->prev = q;
                }
            }
        }
    }
}

void Print(ListInt *l)
{
    printf("Isi List : ");

    if (l->first == NULL)
    {
        printf("[]");
    }
    else
    {
        address curent = l->first;
        while (curent->next != l->first)
        {
            printf("[%d] ", curent->info);
            curent = curent->next;
        }
        printf("[%d] ", curent->info);
    }
}

int main()
{
    ListInt l;
    CreateList(&l);

    address p;
    int isi, pilihan;
    bool stop = false;

    while (!stop)
    {
        system("cls");
        printf("---------- Program Circular List ----------\n\n");
        Print(&l);
        printf("\n\n1. Insert First");
        printf("\n2. Insert Last");
        printf("\n3. Insert After");
        printf("\n4. Delete First");
        printf("\n5. Delete Last");
        printf("\n6. Delete");
        printf("\n7. Traversal");
        printf("\n8. Keluar");
        printf("\n\nMasukkan Pilihan : ");
        scanf("%d", &pilihan);
        if (pilihan == 1)
        {
            printf("Masukkan Angka : ");
            scanf("%d", &isi);
            p = Create(isi);
            First(&l, p);
        }
        else if (pilihan == 2)
        {
            printf("Masukkan Angka : ");
            scanf("%d", &isi);
            p = Create(isi);
            Last(&l, p);
        }
        else if (pilihan == 3)
        {
            printf("Masukkan Angka : ");
            scanf("%d", &isi);
            int sebelum;
            printf("Masukkan Angka Sebelumnya : ");
            scanf("%d", &sebelum);
            p = Create(isi);
            InsertAfter(&l, p, sebelum);
        }
        else if (pilihan == 4)
        {
            DeleteFirst(&l, p);
        }
        else if (pilihan == 5)
        {
            DeleteLast(&l, p);
        }
        else if (pilihan == 6)
        {
            int cari;
            printf("Masukkan angka yang ingin dihapus : ");
            scanf("%d", &cari);
            Delete(&l, p, cari);
        }
        else if (pilihan == 7)
        {
            printf("\nTraversal List : ");

            Print(&l);
            system("pause");
        }
        else if (pilihan == 8)
        {
            stop = true;
        }
    }
    return 0;
}
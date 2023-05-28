#include <stdio.h>
#include <stdlib.h>

typedef struct node *Address;
// Isi dari struct
typedef struct node
{
    int Isi;
    Address Next;
} Node;

// fungsi membuat simpul baru
Address Init(int nilai)
{
    Address p;
    // alokasi node
    p = (Address)malloc(sizeof(Node));
    p->Isi = nilai;
    p->Next = NULL;
    return (p);
}

Address PushFirst(Address a, int val)
{
    Address newNode = Init(val);

    newNode->Next = a;
    a = newNode;

    return a;
}

Address PushLast(Address a, int val)
{
    Address tail = a;
    while (tail->Next != NULL)
    {
        tail = tail->Next;
    }

    Address newNode = Init(val);
    tail->Next = newNode;

    return newNode;
}

Address PushAfterValue(Address a, int val, int searchVal)
{
    Address Indexer = a;

    while (a->Isi != searchVal)
    {
        Indexer = Indexer->Next;
    }

    Address newNode = Init(val);

    newNode->Next = Indexer->Next;
    Indexer->Next = newNode;

    return a;
}

Address PushBeforeValue(Address a, int val, int searchVal)
{
    if (a->Isi == searchVal)
        a = PushFirst(a, val);
    else
    {
        Address Indexer, PrevIndexer;
        Indexer = a;
        do
        {
            PrevIndexer = Indexer;
            Indexer = Indexer->Next;
        } while (Indexer->Isi != searchVal);

        Address newNode = Init(val);
        newNode->Next = Indexer;
        PrevIndexer->Next = newNode;
    }

    return a;
}

Address DeleteFirst(Address a)
{
    if (a == NULL)
        return;

    Address first = a;
    a = a->Next;
    first->Next = NULL;

    free(first);

    return a;
}

Address DeleteLast(Address a)
{
    if (a == NULL)
        return;

    Address Indexer = a, PrevIndexer = NULL;

    while (Indexer->Next != NULL)
    {
        PrevIndexer->Next = Indexer;
        Indexer = Indexer->Next;
    }

    PrevIndexer->Next = NULL;
    free(Indexer);

    return a;
}

Address DeleteAfterValue(Address a, int searchVal)
{
    Address Indexer = a;
    while (Indexer != NULL && Indexer->Next->Isi == searchVal)
    {
        Indexer = Indexer->Next;
    }
    if (Indexer != NULL)
    {
        Address tmp = Indexer->Next;
        Indexer->Next = tmp->Next;
        tmp->Next = NULL;
        free(tmp);
    }
    return (a);
}

void PrintValue(Address head)
{
    Address n = head;
    printf("Daftar nilai linked list : \n");

    while (n != NULL)
    {
        printf("[%d] ", n->Isi);
        n = n->Next;
    };
    printf("\n");
}

// menghitung jumlah node
Address Count(Address head)
{
    int count = 0;
    struct node *p;
    p = head;
    while (p != NULL)
    {
        p = p->Next;
        count++;
    }
    printf("Jumlah node adalah : %d\n", count);
    return (head);
}

Address Dispose(Address head)
{
    if (head == NULL)
    {
        return;
    }
    while (head != NULL)
    {
        Address tmp = head;
        head = head->Next;
        tmp->Next = NULL;
        free(tmp);
    }
    printf("Semua node (simpul) telah dihapus\n");
    return (head);
}

int main()
{
    int pilih, val, val1;
    Address head = NULL;
    while (1)
    {
        system("cls");
        PrintValue(head);
        printf("\n======================== SINGLE LINKED LIST ========================\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert After\n");
        printf("4. Insert Before\n");
        printf("5. Delete First\n");
        printf("6. Delete Last\n");
        printf("7. Delete After\n");
        printf("8. Hitung Jumlah Node\n");
        printf("9. Hapus Keseluruhan Node\n");
        printf("10. Keluar\n");
        printf("Pilihan Anda = ");
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:
        {
            printf("Masukkan nilai = ");
            scanf("%d", &val);
            head = PushFirst(head, val);
            system("cls");
            break;
        }
        case 2:
        {
            printf("Masukkan nilai = ");
            scanf("%d", &val);
            head = PushLast(head, val);
            system("cls");
            break;
        }
        case 3:
        {
            printf("Masukkan nilai = ");
            scanf("%d", &val);
            printf("Masukkan nilai tersebut setelah = ");
            scanf("%d", &val1);
            head = PushAfterValue(head, val, val1);
            system("cls");
            break;
        }
        case 4:
        {
            printf("Masukkan nilai = ");
            scanf("%d", &val);
            printf("Masukkan nilai tersebut sebelum = ");
            scanf("%d", &val1);
            head = PushBeforeValue(head, val, val1);
            system("cls");
            break;
        }
        case 5:
        {
            head = DeleteFirst(head);
            system("cls");
            break;
        }
        case 6:
        {
            head = DeleteLast(head);
            system("cls");
            break;
        }
        case 7:
        {
            printf("Masukkan nilai yang ingin dihapus = ");
            scanf("%d", &val);
            head = DeleteAfterValue(head, val);
            system("cls");
            break;
        }
        case 8:
        {
            head = Count(head);
            system("Pause");
            break;
        }
        case 9:
        {
            head = Dispose(head);
            system("Pause");
            break;
        }
        case 10:
        {
            exit(1);
        }
        default:
        {
            printf("Pilihan tersebut tidak ada");
            break;
        }
        }
    }
    return 0;
}
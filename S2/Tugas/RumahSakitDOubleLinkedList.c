#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    char nama[20];
} Data;

typedef struct node
{
    Data data;
    struct node *next;
    struct node *prev;
} Node;

Node *Create(Node *head)
{
    Node *newNode = malloc(sizeof(Node));

    printf("Masukan Nama: ");
    scanf("%s", newNode->data.nama);

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
        return head;
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

Node *Delete(Node *head)
{
    if (head == NULL)
        return head;

    char name[20];
    printf("Masukan Nama Pasien Yang Ingin Dihapus: ");
    scanf("%s", &name);

    Node *temp = head;

    while (temp->next != NULL && strcmp(temp->data.nama, name))
    {
        temp = temp->next;
    }

    if (temp->next != NULL && temp->prev != NULL)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    else if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
        head = head->next;
    }
    else if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = NULL;
    }

    free(temp);

    return head;
}

void Check(Node *head)
{
    if (head == NULL)
        return;

    char name[20];
    printf("Masukan Nama Pasien Yang Ingin Di Cek: ");
    scanf("%s", name);

    Node *temp = head;
    int counter = 0;

    while (temp->next != NULL && strcmp(temp->data.nama, name))
    {
        counter++;
        temp = temp->next;
    }

    if (counter == 0)
    {
        printf("Atas Nama %s, Mohon Segera Melapor\n", name);
        system("pause");
        return;
    }

    printf("Antrian Atas Nama %s Kurang %d Antrian Lagi\n", name, counter);
    system("pause");
}

void Print(Node *head)
{
    if (head == NULL)
        return;

    int urutan = 1;
    while (head != NULL && head->next != NULL)
    {
        printf("[%d] Nama: %s\n", urutan, head->data.nama);
        head = head->next;
        urutan++;
    }

    printf("[%d] Nama: %s\n\n", urutan, head->data.nama);
}

int main()
{
    Node *headQueue = NULL;
    int pilihan;

    do
    {
        system("cls");
        printf("------------------ANTRIAN RUMAH SAKIT------------------\n");
        printf("Daftar Pasien Dalam Antrian: \n");
        Print(headQueue);
        printf("1. Tambah Antrian.\n");
        printf("2. Hapus Antrian.\n");
        printf("3. Cek Antrian.\n");
        printf("4. Exit.\n");

        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            headQueue = Last(headQueue);
            break;
        case 2:
            headQueue = Delete(headQueue);
            break;
        case 3:
            Check(headQueue);
            break;
        case 4:
            exit(1);
            break;
        default:
            exit(1);
            break;
        }

    } while (pilihan != 4);

    return 0;
}

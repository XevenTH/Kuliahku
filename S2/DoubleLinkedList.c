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

Node *First(Node *head)
{
    Node *newNode = Create(head);
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

Node *InsertAfter(Node *head)
{
    Node *newNode = Create(head);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        int sisip;

        printf("Node Disipkan Setelah Data: ");
        scanf("%d", &sisip);

        Node *temp = head;
        while (temp->next != NULL && temp->data != sisip)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = NULL;

            return head;
        }

        temp->next->prev = newNode;

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next = newNode;
    }

    return head;
}

void CariData(Node *head)
{
    if (head == NULL)
    {
        printf("\n Data Kosong");
        return;
    }

    int cari;

    printf("Data Yang Dicari: ");
    scanf("%d", &cari);

    Node *temp = head;
    while (temp->next != NULL && temp->data != cari)
    {
        temp = temp->next;
    }

    if(temp->next == NULL && temp->data != cari)
    {
        printf("\nData Tidak DItemukan\n");
    }
    else
    {
        printf("\nData Ditemukan\n");
    }

    system("pause");
}

void Print(Node *head)
{
    if (head == NULL)
        return;

    while (head != NULL && head->next != NULL)
    {
        printf("[%d] ", head->data);
        head = head->next;
    }

    printf("[%d] ", head->data);
}

int main()
{
    Node *head = NULL;
    int pilih;

    do
    {
        system("cls");
        Print(head);
        printf("\n\n");
        printf("------------ MENU ------------");
        printf("\n1. Insert First");
        printf("\n2. Insert Last");
        printf("\n3. Insert After");
        printf("\n4. Delete First");
        printf("\n5. Delete Last");
        printf("\n6. Delete After");
        printf("\n7. Cari Data");
        printf("\n8. Exit");

        printf("\nPilihan: ");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
            head = First(head);
            break;
        case 2:
            head = Last(head);
            break;
        case 3:
            head = InsertAfter(head);
            break;
        case 7:
            CariData(head);
            break;
        default:
            break;
        }
    } while (pilih != 8);

    return 0;
}

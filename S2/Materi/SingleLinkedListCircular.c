#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *Create()
{
    Node *newNode = malloc(sizeof(Node));

    printf("Masukan Angka: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    return newNode;
}

Node *First(Node *head)
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

        newNode->next = head;
        tail->next = newNode;

        head = newNode;
    }

    return head;
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
    else if(head->next == head)
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
    }

    return head;
}

Node *DeleteFirst(Node *head)
{
    if (head == NULL)
    {
        printf("\n SImpul Sedang Kosong \n");
    }
    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {

        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }

        Node *tmp = head;

        tail->next = head->next;
        head = head->next;

        free(tmp);
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
            printf("[%d] ", tail->data);
            tail = tail->next;
        }

        printf("[%d] \n", tail->data);
    }
}

int main()
{
    Node *head = NULL;
    int pilih = 0;

    do
    {
        Print(head);
        printf("\nMenu : \n");
        printf("1. Insert Node\n");
        printf("2. Insert First\n");
        printf("3. Delete First\n");
        printf("4. Delete Last\n");
        printf("5. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
            system("cls");
            head = Last(head);
            break;
        case 2:
            system("cls");
            head = First(head);
            break;
        case 3:
            system("cls");
            head = DeleteFirst(head);
            break;
        case 4:
            system("cls");
            head = DeleteLast(head);
            break;
        case 5:
            exit(1);
            break;
        default:
            exit(1);
            break;
        }
        system("cls");
    } while (pilih != 0);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct
{
    int data[MAX];
    int front;
    int rear;
} Queue;

void Init(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

bool IsEmpty(Queue *q)
{
    return q->front == -1 && q->rear == -1;
}

bool IsFull(Queue *q)
{
    return q->rear == MAX - 1;
}

int Size(Queue *queue)
{
    return queue->rear + 1;
}

void Enqueue(Queue *q, int val)
{
    if (IsFull(q))
        return;
    if (IsEmpty(q))
        q->front++;

    q->data[++q->rear] = val;

    return;
}

void Dequeue(Queue *q)
{
    if (IsEmpty(q))
        return;
    if (q->front == 0 && q->rear == 0)
    {
        q->front--;
        q->rear--;
        return;
    }

    for (int i = q->front + 1; i < q->rear + 1; i++)
        q->data[i - 1] = q->data[i];

    q->rear--;
    return;
}

int Front(Queue *q)
{
    !IsEmpty(q) ? q->data[q->front] : -1;
}

void HandleAntrian(Queue *q)
{
    if (IsEmpty(q))
        return;

    for (int i = q->front; i < q->rear + 1; i++)
    {
        printf("%d, ", q->data[i]);
    }
}

int main()
{
    Queue newQueue;
    Init(&newQueue);

    int option;

    while (1)
    {
        printf("---------------------------------------------------------------\n");
        printf("Queue: ");
        HandleAntrian(&newQueue);
        printf("\t|\tFront: %d", Front(&newQueue));
        printf("\t|\tSize: %d\n", Size(&newQueue));
        printf("---------------------------------------------------------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print\n");
        printf("---------------------------------------------------------------\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &option);
        if (option == 1)
        {
            int value;
            printf("Masukkan nilai baru: ");
            scanf("%d", &value);
            Enqueue(&newQueue, value);
        }
        else if (option == 2)
        {
            Dequeue(&newQueue);
        }
        else if (option == 3)
        {
            break;
        }
        
        else
        {
            printf("Opsi tidak valid!\n");
        }
        system("clear"); // gunakan system("cls") pada sistem operasi Windows
    }

    return 0;
}

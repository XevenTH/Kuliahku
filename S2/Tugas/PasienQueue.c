#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

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
    {
        q->front++;
        q->data[++q->rear] = val;
        return;
    }

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

void QueueHandler(Queue *q)
{
    if (!IsEmpty(q))
    {
        for (int i = q->front; i < q->rear + 1; i++)
        {
            if (q->data[i] < 5)
            {
                printf("ditangani dokter umum\n");
            }
            else
            {
                printf("ditangani dokter spesialis\n");
            }
        }

        q->front = -1;
        q->rear = -1;

        return;
    }
}

int main()
{
    Queue newQueue;
    Init(&newQueue);

    int jumlahAntrian;

    printf("Masukan Jumlah Antrian : ");
    scanf("%d", &jumlahAntrian);


    for (int i = 1; i <= jumlahAntrian; i++)
    {
        int val = 0;

        printf("Antrian Ke-%d : ", i);
        scanf("%d", &val);

        Enqueue(&newQueue, val);
    }

    printf("\nSize Sebelum : %d\n", Size(&newQueue));

    QueueHandler(&newQueue);

    printf("\nSize Sesudah : %d", Size(&newQueue));

    return 0;
}

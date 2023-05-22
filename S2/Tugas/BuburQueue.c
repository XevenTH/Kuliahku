#include <stdio.h>
#include <stdbool.h>

#define MAX 15

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
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
        return;
    }

    for (int i = q->front; i < Size(q) - 1; i++)
        q->data[i] = q->data[i + 1];

    q->rear--;
    return;
}

int Front(Queue *q)
{
    if (!IsEmpty(q))
        return q->data[q->front];
}

void PrintQueueData(Queue *q)
{
    printf("[");
    for (int i = 0; i < Size(q); i++)
    {
        if (i == Size(q) - 1)
        {
            printf("%d", q->data[i]);
            continue;
        }

        printf("%d, ", q->data[i]);
    }
    printf("]\n");
}

void InputQueueData(Queue *q, int count)
{
    for (int i = 0; i < count; i++)
    {
        int val;
        scanf("%d", &val);

        Enqueue(q, val);
    }
}

void QueueCompareHandler(Queue *sQ, Queue *bQ)
{
    if (IsEmpty(sQ))
        return;
    if (IsEmpty(bQ))
        return;

    bool CompareableValue = true;

    while (!IsEmpty(sQ) && !IsEmpty(bQ) && CompareableValue)
    {
        CompareableValue = false;

        if (Front(sQ) == Front(bQ))
        {
            Dequeue(sQ);
            Dequeue(bQ);
        }
        else
        {
            Enqueue(sQ, Front(sQ));
            Dequeue(sQ);
        }

        for (int i = 0; i < Size(sQ); i++)
            if (sQ->data[i] == Front(bQ))
                CompareableValue = true;
    }
}

int main(int argc, char const *argv[])
{
    Queue sQueue;
    Queue bQueue;
    int sCount, bCount;

    Init(&sQueue);
    Init(&bQueue);

    printf("Masukan Jumlah Siswa: ");
    scanf("%d", &sCount);
    printf("Masukan Jumlah Bubur: ");
    scanf("%d", &bCount);

    printf("Masukan Permintaan Siswa : \n");
    InputQueueData(&sQueue, sCount);

    printf("Masukan Bubur Yang Tersedia : \n");
    InputQueueData(&bQueue, bCount);

    printf("Siswa : ");
    PrintQueueData(&sQueue);
    printf("Bubur : ");
    PrintQueueData(&bQueue);

    QueueCompareHandler(&sQueue, &bQueue);

    printf("===================================\n");
    printf("Sisa Siswa : %d", Size(&sQueue));

    return 0;
}

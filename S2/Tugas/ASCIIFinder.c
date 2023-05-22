#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 25

typedef struct
{
    char data[MAX];
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

int Front(Queue *q)
{
    if (!IsEmpty(q))
        return q->data[q->front];
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

char Dequeue(Queue *q)
{
    if (IsEmpty(q))
        return ' ';
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
        return ' ';
    }

    char temp = Front(q);
    for (int i = q->front; i < Size(q) - 1; i++)
        q->data[i] = q->data[i + 1];

    q->rear--;
    return temp;
}

int findFirstUniqueCharacterIndex(char *string)
{
    Queue queue;
    Init(&queue);

    for (int i = 0; i < strlen(string); i++)
    {
        Enqueue(&queue, string[i]);
    }

    for (int i = 0; i <= Size(&queue); i++)
    {
        for (int j = 1; j <= Size(&queue); j++)
        {
            if (queue.data[0] == queue.data[j])
                break;
            if (j == Size(&queue))
                return i;
        }

        Enqueue(&queue, queue.data[0]);
        Dequeue(&queue);
    }
}

int main()
{
    char string[25];
    printf("Masukan Kata: ");
    scanf("%s", string);

    int index = findFirstUniqueCharacterIndex(string);
    printf("Karakter Unik Pertama Berada Di Index: %d\n", index);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef char QData;

struct Node
{
    QData data;
    struct Node *next;
};

typedef struct QueueLinked
{
    // 队头
    struct Node *front;
    // 队尾
    struct Node *rear;
} QueueLinked;

void init(QueueLinked *queue)
{
    queue->front = queue->rear = malloc(sizeof(struct Node));
    queue->front->next = NULL;
}

void enQueue(QueueLinked *queue, QData data)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    queue->rear->next = node;
    queue->rear = node;
}

void printQueue(QueueLinked queue)
{
    struct Node *node = queue.front->next;
    while (node != NULL)
    {
        printf("%c --->", node->data);
        node = node->next;
    }
    printf("\n");
}

QData deQueue(QueueLinked *queue)
{
    if (queue->front == queue->rear)
    {
        return NULL;
    }

    struct Node *head = queue->front->next;
    QData nodeData = head->data;
    queue->front->next = head->next;
    if (queue->rear == head)
    {
        queue->rear = queue->front;
    }
    
    free(head);
    return nodeData;
}

int main()
{
    QueueLinked queue;
    init(&queue);

    enQueue(&queue, 'A');
    enQueue(&queue, 'B');
    enQueue(&queue, 'C');
    printQueue(queue);

    printf("%c \n", deQueue(&queue));
    printf("%c \n", deQueue(&queue));
    printf("%c \n", deQueue(&queue));
}
#include <stdio.h>
#include <stdlib.h>

typedef char QData;

typedef struct
{
    QData data;
    struct Node *next;
} Node;

typedef struct QueueLinked
{
    // 队头
    Node *front;
    // 队尾
    Node *rear;
} QueueLinked;

void init(QueueLinked *queue)
{
    queue->front = queue->rear = malloc(sizeof(Node));
    queue->front->next = NULL;
}

void enQueue(QueueLinked *queue, QData data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    queue->rear->next = node;
    queue->rear = node;
}

void printQueue(QueueLinked queue)
{
    Node *node = queue.front->next;
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

    Node *head = queue->front->next;
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
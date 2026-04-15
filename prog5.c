#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

int front(struct Queue* q) {
    if(q->front == NULL)
        return -1;
    return q->front->data;
}

int is_empty(struct Queue* q) {
    return q->front == NULL;
}

int main() {
    struct Queue q;
    q.front = q.rear = NULL;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("%d\n", front(&q));
    printf("%d\n", is_empty(&q));

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void push(struct Stack* s, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(struct Stack* s) {
    if(s->top == NULL)
        return -1;

    struct Node* temp = s->top;
    int val = temp->data;
    s->top = temp->next;
    free(temp);
    return val;
}

int peek(struct Stack* s) {
    if(s->top == NULL)
        return -1;
    return s->top->data;
}

int empty(struct Stack* s) {
    return s->top == NULL;
}

int main() {
    struct Stack s;
    s.top = NULL;

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("%d\n", peek(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", peek(&s));
    printf("%d\n", empty(&s));

    return 0;
}

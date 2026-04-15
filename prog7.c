#include <stdio.h>
#include <stdlib.h>

struct CircularNode {
    int data;
    struct CircularNode* next;
};

struct CircularLinkedList {
    struct CircularNode* head;
};

void insert_at_beginning(struct CircularLinkedList* list, int data) {
    struct CircularNode* newNode = (struct CircularNode*)malloc(sizeof(struct CircularNode));
    newNode->data = data;

    if(list->head == NULL) {
        newNode->next = newNode;
        list->head = newNode;
        return;
    }

    struct CircularNode* temp = list->head;
    while(temp->next != list->head)
        temp = temp->next;

    newNode->next = list->head;
    temp->next = newNode;
    list->head = newNode;
}

void traverse(struct CircularLinkedList* list) {
    if(list->head == NULL)
        return;

    struct CircularNode* temp = list->head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != list->head);
}

int main() {
    struct CircularLinkedList list;
    list.head = NULL;

    insert_at_beginning(&list, 10);
    insert_at_beginning(&list, 5);
    insert_at_beginning(&list, 1);

    traverse(&list);

    return 0;
}

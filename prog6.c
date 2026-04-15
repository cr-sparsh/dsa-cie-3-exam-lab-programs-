#include <stdio.h>
#include <stdlib.h>

struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
};

struct DoublyLinkedList {
    struct DoublyNode* head;
};

void insert_at_beginning(struct DoublyLinkedList* list, int data) {
    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = list->head;

    if(list->head != NULL)
        list->head->prev = newNode;

    list->head = newNode;
}

void insert_at_end(struct DoublyLinkedList* list, int data) {
    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    newNode->data = data;
    newNode->next = NULL;

    if(list->head == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
        return;
    }

    struct DoublyNode* temp = list->head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void traverse_forward(struct DoublyLinkedList* list) {
    struct DoublyNode* temp = list->head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct DoublyLinkedList list;
    list.head = NULL;

    insert_at_beginning(&list, 10);
    insert_at_beginning(&list, 5);
    insert_at_end(&list, 20);
    insert_at_end(&list, 30);

    traverse_forward(&list);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert_at_beginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insert_at_end(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void delete_node(int data) {
    struct Node *temp = head, *prev = NULL;

    if(temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void traverse() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    insert_at_beginning(10);
    insert_at_beginning(5);
    insert_at_end(20);
    insert_at_end(30);

    traverse();
    printf("\n");

    delete_node(20);

    traverse();

    return 0;
}

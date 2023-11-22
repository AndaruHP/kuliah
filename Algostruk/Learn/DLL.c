#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
    }
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        if (current->prev != NULL) {
            current->prev->next = NULL;
        } else {
            head = NULL;
        }
        free(current);
    }
}

void printList() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* current = head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    insertAtEnd(10);
    insertAtBeginning(5);
    insertAtEnd(20);
    insertAtBeginning(3);
    deleteAtBeginning();
    deleteAtEnd();
    printList();
    return 0;
}



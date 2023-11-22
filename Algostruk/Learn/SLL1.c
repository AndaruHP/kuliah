#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insertNode(Node **head, int value, int position) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *currentNode = *head;
    int i;
    for (i = 1; i < position - 1 && currentNode->next != NULL; i++) {
        currentNode = currentNode->next;
    }

    if (i == position - 1) {
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    } else {
        printf("Invalid position\n");
    }
}

void printList(Node *head) {
    Node *currentNode = head;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    insertNode(&head, 1, 1);
    insertNode(&head, 2, 2);
    insertNode(&head, 3, 3);
    insertNode(&head, 4, 4);

    printf("Before insertion: ");
    printList(head);

    insertNode(&head, 100, 4);

    printf("After insertion: ");
    printList(head);

    return 0;
}

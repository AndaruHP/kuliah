#include<stdio.h>
#include<stdlib.h>

typedef struct Coba {
    int nilai;
    struct Coba *next;
} Coba;

Coba *create(int data){
    Coba *newnode = (Coba*) malloc (sizeof(Coba));
    newnode->nilai = data;
    newnode->next = NULL;
    return newnode;
}

void append(Coba **head, int data){
    Coba *node = create(data);
    if(*head == NULL){
        *head = node;
        return;
    }

    Coba *curr = head;

    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = node;
}

int main(){
    Coba *head = NULL;
    Coba *node = (Coba*) malloc (sizeof(Coba));

    node->nilai = 45;
    node->next = NULL;
    head = node;

    append(&head, 40);
    append(&head, 5);

    while(head != NULL){
        printf("%d ", head->nilai);
        head = head->next;
    }
}
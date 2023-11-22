#include<stdio.h>
#include<stdlib.h>

typedef struct Coba{
    int nilai;
    struct Coba *next;
} Coba;

void insertdepan(Coba **head, Coba **tail, int data){
    Coba *node = (Coba*) malloc (sizeof(Coba));
    node->nilai = data;
    node->next = NULL;

    if(*head == NULL){
        *head = node;
        *tail = node;
    } else {
        node->next = *head;
        *head = node;
    }
}

void insertbelakang(Coba **head, Coba **tail, int data){
    Coba *node = (Coba*) malloc (sizeof(Coba));
    node->nilai = data;
    node->next = NULL;

    if(*head == NULL){
        *head = node;
        *tail = node;
    } else {
        (*tail)->next = node;
        *tail = node;
    }
}


void delete(Coba **head){
    Coba *curr = *head;
    Coba *temp;
    while(curr != NULL){
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    //*head = NULL;
}

int main(){
    Coba *head, *tail;
    head = tail = NULL;
    
    insertdepan(&head, &tail, 40);
    insertdepan(&head, &tail, 30);
    insertdepan(&head, &tail, 20);

    insertbelakang(&head, &tail, 40);
    insertbelakang(&head, &tail, 30);
    insertbelakang(&head, &tail, 20);

    Coba *curr = head;

    while(curr != NULL){
        printf("%d\n", curr->nilai);
        curr = curr->next;
    }

    delete(&head);

    //curr = head;
    if(curr == NULL) printf("Hapus Semua");

}
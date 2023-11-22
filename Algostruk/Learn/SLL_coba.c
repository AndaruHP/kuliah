#include<stdio.h>
#include<stdlib.h>

typedef struct SLL{
    int nilai;
    struct SLL *next;
} SLL;

void tambahdepan(SLL **head, SLL **tail, int nilai){
    SLL *node = (SLL*) malloc (sizeof(SLL));
    node->nilai = nilai;
    node->next = NULL;

    if(*head == NULL){
        *head = *tail = node;   
    } else {
        node->next = *head;
        *head = node;
    }
}

void tambahbelakang(SLL **head, SLL **tail, int nilai){
    SLL *node = (SLL*) malloc (sizeof(SLL));
    node->nilai = nilai;
    node->next = NULL;

    if(*head == NULL){
        *head = *tail = node;
    } else {
        (*tail)->next = node;
        *tail = node;
    }
}

void hapussemua(SLL **head){
    SLL *curr = *head;
    SLL *temp;

    while(curr != NULL){
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    *head = NULL;
}

void hapussatu(SLL **head, int nilai){
    SLL *curr = *head;
    SLL *prev = NULL;

    while(curr != NULL && curr->nilai != nilai){
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){
        printf("\nLinked List kosong\n");
        return;
    }

    if(prev == NULL){
        *head = curr->next;
    } else {
        prev->next = curr->next;
        //curr di free karena akan dideklarasikan lagi di atas bahwa curr = *head
    }

    free(curr);
}

void print(SLL **head){
    if(*head == NULL){
        printf("\nLinked List kosong\n");
        return;
    } else {
        SLL *curr = *head;
        while(curr != NULL){   
            printf("%d ", curr->nilai);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main(){
    SLL *head = NULL;
    SLL *tail = NULL;

    int pilihan;
    int data;
    do {
        printf("1. Tambah depan\n2. Tambah belakang\n3. Hapus semua\n4. Hapus berdasarkan nilai\n5. Print\n6. Exit");
        printf("\nPilihan: ");
        scanf("%d", &pilihan);
        switch(pilihan){
            case 1:
                printf("Masukkan nilai: ");
                scanf("%d", &data);
                tambahdepan(&head, &tail, data);
                break;
            case 2:
                printf("Masukkan nilai: ");
                scanf("%d", &data);
                tambahbelakang(&head, &tail, data);
                break;
            case 3:
                hapussemua(&head);
                break;
            case 4:
                printf("Masukkan nilai: ");
                scanf("%d", &data);
                hapussatu(&head, data);
            case 5:
                print(&head);
                break;
            default :
                break;
        }
    } while(pilihan != 6);

}
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef struct Mahasiswa {
    char nama[100];
    char jurusan[30];
    int nim;
    struct Mahasiswa *next;
} Mahasiswa;

void insertnew(Mahasiswa** head){
    Mahasiswa *baru = (Mahasiswa*) malloc (sizeof(Mahasiswa));
    printf("Nim\t: ");
    scanf("%d", &baru->nim);
    printf("Nama\t: ");
    scanf("%s", baru->nama);
    printf("Jurusan\t: ");
    scanf("%s", baru->jurusan);
    baru->next = *head; 
    *head = baru;
}

void cetak(Mahasiswa* head){
    if(head == NULL){
        printf("Link kosong\n");
        return;
    }
    printf("Data: \n");
    while(head != NULL){
        printf("Nama\t: %s\nJurusan\t: %s\nNIM\t: %d\n", head->nama, head->jurusan, head->nim);
        head = head->next;
    }
}

void clear(Mahasiswa** head){
    Mahasiswa* now = *head;
    Mahasiswa* next;
    while(now != NULL){
        next = now->next;
        free(now);
        now = next;
    }
}

void clearfirst(Mahasiswa** head){
    if(*head == NULL){
        printf("Link Kosong\n");
        return;
    }
    Mahasiswa* temp = *head;
    *head = temp->next;
    free(temp);
    printf("Data pertama berhasil dihapus\n");
}

void clearbynim(Mahasiswa** head, int nim){
    Mahasiswa* now = *head;
    Mahasiswa* seb = NULL;
    int banyak = 0;
    while(now != NULL){
        if(now->nim == nim){
            banyak = 1;
            break;
        }

        seb = now;
        now = now->next;
    }

    if(banyak){
        if(seb == NULL){
            *head = now->next;
        } else {
            seb->next = now->next;
        }
        free(now);
        printf("Penghapusan berhasil\n");    
    } else {
        printf("Data tidak ditemukan\n");
    }
}

int main(){
    Mahasiswa* head = NULL;

    int pilihan, nim;
    do {
        printf("1. Insert new node\n2. Print linked list\n3. Delete all data\n4. Delete first data\n4. Delete first data\n5. Delete data by NIM\n6. Exit\nPilihan: ");
        scanf("%d", &pilihan);

        switch(pilihan){
            case 1:
                insertnew(&head);
                printf("\n");
            break;
            case 2:
                cetak(head);
                printf("\n");
            break;
            case 3:
                clear(&head);
                printf("\n");
            break;
            case 4:
                clearfirst(&head);
                printf("\n");
            break;
            case 5:
                printf("NIM\t: ");
                scanf("%d", &nim);
                clearbynim(&head, nim);
                printf("\n");
            break;
            case 6:
                exit(0);
            default:
            break;
        }

    } while(pilihan != 6);

    return 0;
}
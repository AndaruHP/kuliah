#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

int banyak = 0;

typedef struct Lagu {
    char nama[20];
    char judul[20];
    char genre[20];
    int tahun;
    struct Lagu *next;
} Lagu;

void readfile(Lagu **head, Lagu **tail){
    FILE *fp = fopen("lagu.txt", "r+");
    
    if(fp == NULL){
        printf("\nData Kosong\n");
        return;
    }

    while(!feof(fp)){
        banyak++;
        Lagu *node = (Lagu*) malloc (sizeof(Lagu));
        fscanf(fp, "%[^//]//%[^//]//%[^//]//%d\n", node->judul, node->nama, node->genre, &node->tahun);

        node->next = NULL;

        if(*head == NULL){
            *head = *tail = node;
        } else {
            (*tail)->next = node;
            *tail = node;
        }
    }
    
    fclose(fp);

}

void Lihat(Lagu **head){
    Lagu *curr = *head;

    if(*head == NULL){
        printf("\nLinked List Kosong\n");
        return;
    } 
    while(curr != NULL) {
        printf("%s\t%s\t%s\t%d\n", curr->nama, curr->judul, curr->genre, curr->tahun);
        curr = curr->next;
    }
}

void Hapus(Lagu **head, Lagu **tail, char judul[]){
    Lagu *curr = *head;
    Lagu *prev = *head;

    int found = 0;

    if(*head == NULL){
        printf("\nData kosong\n");
        return;
    }

    while(curr != NULL){
        if(strcmp(judul, curr->judul) == 0){
            found = 1;
            break;
        }
        prev = curr;
        curr = curr->next;
    }


    if(found){
        if(curr == *head && curr == *tail){
            *head = *tail = NULL;
        } else if(curr == *head){
            *head = (*head)->next;
        } else if(curr == *tail){
            *tail = prev;
            (*tail)->next = NULL;
        } else {
            prev->next = curr->next;
        }

        free(curr);

        printf("\nBerhasil dihapus\n");

        FILE *fp = fopen("lagu.txt", "w");
        curr = *head;

        while(curr != NULL){
            fprintf(fp, "%s//%s//%s//%d\n", curr->nama, curr->judul, curr->genre, curr->tahun);
            curr = curr->next;
        }

        fclose(fp);
    } else {
        printf("\nGagal dihapus\n");
    }


}

void Tambah(Lagu **head, Lagu **tail){
    banyak++;
    Lagu *tambah = (Lagu*) malloc (sizeof(Lagu));

    printf("Masukkan nama penyanyi: ");
    scanf("%[^\n]", tambah->nama);
    fflush(stdin);
    printf("Masukkan judul lagu: ");
    scanf("%[^\n]", tambah->judul);
    fflush(stdin);
    printf("Masukkan genre lagu: ");
    scanf("%[^\n]", tambah->genre);
    fflush(stdin);
    printf("Masukkan tahun rilis: ");
    scanf("%d", &tambah->tahun);
    fflush(stdin);

    FILE *fp = fopen("lagu.txt", "a+");
    fprintf(fp, "%s//%s//%s//%d\n", tambah->nama, tambah->judul, tambah->genre, tambah->tahun);
    fclose(fp);

    if(*head == NULL){
        *head = *tail = tambah;
    } else {
        (*tail)->next = tambah;
        tambah->next = NULL;
        *tail = tambah;
    }


}

void Cari(Lagu **head){
    printf("Masukkan judul: ");
    char awal[20];
    scanf("%[^\n]", awal);
    Lagu *curr = *head;

    if(*head == NULL){
        printf("\nLinked List Kosong\n");
        return;
    } 
    while(curr != NULL) {
        if(strncmp(awal, curr->judul, strlen(awal)) == 0){
            printf("%s\t%s\t%s\t%d\n", curr->nama, curr->judul, curr->genre, curr->tahun);
            exit(1);
        }
        curr = curr->next;
    }
    printf("\nTidak ada\n");
}


int main(){
    Lagu *head = NULL;
    Lagu *tail = NULL;

    readfile(&head, &tail);

    int pilihan;

    char judul[20];

    do {
        printf("1. Nambah Lagu\n2. Hapus Lagu\n3. Tampilkan data\n4. Banyak\n5. Cari\n6. Exit\nPilihan: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        switch(pilihan){
            case 1:
                Tambah(&head, &tail);
            break;
            case 2:
                printf("\nNama lagu yang ingin dihapus: ");
                scanf("%[^\n]", judul);
                Hapus(&head, &tail, judul);
            break;
            case 3:
                Lihat(&head);
            break;
            case 4:
                printf("\nBanyak lagu = %d\n", banyak);
            break;
            case 5:
                Cari(&head);
            break;
            default:
            break;
        }

    } while(pilihan != 6);
}
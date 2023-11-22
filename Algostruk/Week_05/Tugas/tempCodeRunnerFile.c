#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

typedef struct Lagu {
    char singer[20];
    char album[20];
    char song[20];
    int tahun;
    struct Lagu *prev, *next;
} Lagu;

Lagu *head = NULL;
Lagu *tail = NULL;

void readfile(){
    FILE *fp = fopen("playlist.txt", "r+");
    int k = 0;

    if(fp == NULL){
        printf("\nData kosong\n");
        return;
    }

    while(!feof(fp)){
        Lagu *node = (Lagu*) malloc (sizeof(Lagu));
        fscanf(fp, "%[^*]*%[^*]*%[^*]*%d\n", node->singer, node->album, node->song, &node->tahun);

        node->next = NULL;
        node->prev = tail;

        if(head == NULL){
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        k++;
    }

    fclose(fp);
}

void tambahdata(){
    Lagu *node = (Lagu*) malloc (sizeof(Lagu));
    printf("Penyanyi\t: ");
    scanf("%s", node->singer);
    printf("Album\t: ");
    scanf("%s", node->album);
    printf("Title\t: ");
    scanf("%s", node->song);
    printf("Tahun\t: ");
    scanf("%d", &node->tahun);

    FILE *fp = fopen("playlist.txt", "a+");
    fprintf(fp, "%s*%s*%s*%d\n", node->singer, node->album, node->song, node->tahun);
    fclose(fp);

    if(head == NULL){
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }

    printf("Data Berhasil Ditambahkan\n");
}

void tampildata(){
    Lagu *now = head;
    if(now == NULL){
        printf("Tidak ada data\n");
        return;
    }

    printf("+----------------------+----------------------+---------------------+-------+\n");
    printf("| Singer               | Album                | Song                | Year  |\n");
    printf("+----------------------+----------------------+---------------------+-------+\n");

    while(now != NULL){
        printf("| %-20s | %-20s | %-20s | %-5d |\n", now->singer, now->album, now->song, now->tahun);
        now = now->next;
    }

    printf("+----------------------+----------------------+---------------------+-------+\n");
}


void hapusdata(){
    if(head == NULL){
        printf("\nData Kosong\n");
        return;
    }

    char judul[20];
    printf("Masukkan judul lagu: ");
    scanf("%[^\n]", judul);
    Lagu *temp;
    temp = head;
    while(temp != NULL){
        if(strcmp(judul, temp->song) == 0){
            if(temp == head){
                head = temp->next;
                if(head != NULL){
                    head->prev = NULL;
                }
                free(temp);
                printf("%s berhasil dihapus\n", judul);
                break;
            } else if(temp->next == NULL){
                temp->prev->next = NULL;
                free(temp);
                printf("%s berhasil dihapus\n", judul);
                break;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
                printf("%s berhasil dihapus\n", judul);
                break;
            }
        }
        temp = temp->next;
    }
    printf("\nData tidak dapat ditemukan\n");

    if(temp == NULL){
        printf("\nData tidak ditemukan\n");
    }

    FILE *fp = fopen("playlist.txt", "w");
    Lagu *now = head;
    while(now != NULL){
        fprintf(fp, "%s*%s*%s*%d\n", now->singer, now->album, now->song, now->tahun);
        now = now->next;
    }
    fclose(fp);
}

int main(){
    int pilihan;
    readfile();
    do {
        printf("Selama Datang\n1. Tampilkan data\n2. Tambah data\n3. Hapus data\n4. Exit\nPilihan: ");
        scanf("%d", &pilihan);
        switch(pilihan){
            case 1:
                tampildata();
            break;
            case 2:
                tambahdata();
            break;
            case 3:
                hapusdata();
            break;
            default:
                printf("\nPilihan salah\n");
            break;
        }
    } while(pilihan != 4);

    printf("\nSelamat tinggal\n");
}
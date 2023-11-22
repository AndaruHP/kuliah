#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

/*
    Nama    : Andaru Hymawan Primayudha
    NIM     : 0000007547
    Kelas   : G
    Nilai   : -
*/

int totalbuku = 0;

typedef struct Buku {
    char judul[30];
    char penulis[30];
    char penerbit[30];
    char genre[30];
    int tahun;
    int urutan;
    struct Buku *next;
} Buku;

void readfile(Buku **head, Buku **tail){
    FILE *fp = fopen("data_buku.txt", "r");

    if(fp == NULL){
        printf("\nData Kosong\n");
        return;
    }

    while(!feof(fp)){
        totalbuku++;
        Buku *node = (Buku*) malloc (sizeof(Buku));
        fscanf(fp, "%[^#]#%[^#]#%[^#]#%d#%[^\n]\n", node->judul, node->penulis, node->penerbit, &node->tahun, node->genre);
        node->urutan = totalbuku;

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

void Tampil(Buku **head, Buku **tail){
    Buku *curr = *head;
    Buku *temp = curr;

    int pilihan2;

    if(*head == NULL){
        printf("\nTidak ada data\n");

    }
    do {
        printf("Buku ke-%d dari %d\n", curr->urutan, totalbuku);
        printf("====================================\n");
        printf("Judul Buku\t: %s\n", curr->judul);
        printf("Penulis Buku\t: %s\n", curr->penulis);
        printf("Tahun Terbit\t: %d\n", curr->tahun);
        printf("Penerbit\t: %s\n", curr->penerbit);
        printf("Genre\t\t: %s\n", curr->genre);
        printf("====================================\n");

        printf("\n1. Selanjutnya\n2. Keluar\nPilihan: ");
        scanf("%d", &pilihan2);

        switch(pilihan2){
            case 1:
                system("cls");
                temp = temp->next;
                if(temp == NULL){
                    temp = *head;
                }
                curr = temp;
            break;
            default:
            break;
        }
    } while(pilihan2 != 2);
    system("cls");

}

void Total(){
    printf("Terdapat %d buku di dalam database perpustakaan", totalbuku);;
    //system("cls");
}

void Tambah(Buku **head, Buku **tail){
    totalbuku++;
    Buku *tambah = (Buku*) malloc (sizeof(Buku));
    tambah->next = NULL;
    printf("\nMasukkan Judul Buku: ");
    scanf("%[^\n]", tambah->judul);
    fflush(stdin);
    printf("Masukkan Penulis Buku: ");
    scanf("%[^\n]", tambah->penulis);
    fflush(stdin);
    printf("Masukkan Tahun Terbit: ");
    scanf("%d", &tambah->tahun);
    fflush(stdin);
    printf("Masukkan Penerbit: ");
    scanf("%[^\n]", tambah->penerbit);
    fflush(stdin);
    printf("Masukkan Genre: ");
    scanf("%[^\n]", tambah->genre);
    fflush(stdin);
    printf("\n\nBuku berhasil ditambahkan ke dalam sistem");
    tambah->urutan = totalbuku;

    FILE *fp = fopen("data_buku.txt", "a+");
    fprintf(fp, "%s#%s#%s#%d#%s\n", tambah->judul, tambah->penulis, tambah->penerbit, tambah->tahun, tambah->genre);
    fclose(fp);

    if(*head == NULL){
        *head = *tail = tambah;
    } else {
        (*tail)->next = tambah;
        *tail = tambah;
    }
    //system("cls");
}


void Hapus(Buku **head){
    Buku *curr = *head;
    *head = (*head)->next;

    free(curr);

    Buku *temp = *head;

    while(temp != NULL){
        temp->urutan -= 1;
        temp = temp->next;
    }

    FILE *fp = fopen("data_buku.txt", "a");
    while(temp != NULL){
        fprintf(fp, "%s#%s#%s#%d#%s\n", temp->judul, temp->penulis, temp->penerbit, temp->tahun, temp->genre);
        temp = temp->next;
    }
    fclose(fp);

    totalbuku--;
    system("cls");
}

void Cari(Buku **head){
    char judul[30];
    printf("Masukkan judul buku yang dicari: ");
    scanf("%[^\n]", judul);
    fflush(stdin);

    Buku *curr = *head;
    while(curr != NULL){
        if(strncmp(judul, curr->judul, strlen(judul)) == 0){
            printf("Data ditemukan di dalam sistem\n");
            printf("Judul Buku\t: %s\n", curr->judul);
            printf("Penulis Buku\t: %s\n", curr->penulis);
            printf("Tahun Terbit\t: %d\n", curr->tahun);
            printf("Penerbit\t: %s\n", curr->penerbit);
            printf("Genre\t\t: %s\n", curr->genre);
            exit(1);
        }
        curr = curr->next;
    }

    printf("\nBuku tidak ditemukan\n");
    //system("cls");
}

int main(){
    Buku *head = NULL;
    Buku *tail = NULL;

    readfile(&head, &tail);

    int pilihan;

    do {
        //system("cls");
        printf("====================================\n");
        printf("    Sistem Manajemen Perpustakaan    \n");
        printf("====================================\n\n");
        printf("1. Tampilkan Semua Buku\n2. Tambah Buku\n3. Hapus Buku\n4. Total Buku \n5. Cari Buku\n6. Exit\nPilihan: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        switch(pilihan){
            case 1:
                system("cls");
                Tampil(&head, &tail);
                printf("\n");
            break;
            case 2:
                system("cls");
                Tambah(&head, &tail);
                printf("\n");
            break;
            case 3:
                system("cls");
                Hapus(&head);
                printf("\n");
            break;
            case 4:
                system("cls");
                Total();
                printf("\n");
            break;
            case 5:
                system("cls");
                Cari(&head);
                printf("\n");
            break;
            default:
            break;
        }

    } while(pilihan != 6);
}

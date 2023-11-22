#include<stdio.h>
#include<stdlib.h>

typedef struct Buku {
    char judul[30];
    char pengarang[30];
    int tahun;
    int halaman;
} Buku;

int main(){
    Buku *head = NULL;
    Buku *tail = NULL;

    int pilihan;

    do {
        printf("Perpustakaan");
        printf("1. Tambah Buku\n2. Hapus Buku\n3. Cari Buku\n4. Total Buku\n5. Keluar\nPilihan: ");
        scanf("%d", &pilihan);
    } while();
}
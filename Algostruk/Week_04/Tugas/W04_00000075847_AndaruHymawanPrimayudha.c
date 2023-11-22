#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Mahasiswa{
    char nama[50];
    char jurusan[20];
    int nim;
    struct Mahasiswa* link;
} Mahasiswa;

void buatbaru(Mahasiswa** head){
    Mahasiswa* new = (Mahasiswa*) malloc (sizeof(Mahasiswa));
    //untuk membuat node baru
    printf("Masukkan nama\t: ");
    scanf("%s", new->nama);
    printf("Masukkan jurusan\t: ");
    scanf("%s", new->jurusan);
    printf("Masukkan NIM\t: ");
    scanf("%s", new->nim);
    new->link = *head;
    //mengisi alamat baru menggunakan alamat head
    *head = new;
    //posisi head dipindahkan ke node
}

void ngeprint(Mahasiswa* head){
    if(head == NULL){
        printf("Linked list kosong\n");
    }

    while(head != NULL){
        printf("Nama\t: %s\nJurusan\t: %s\nNIM\t: %d\n", head->nama, head->jurusan, head->nim);
        head = head->link;
        //setelah ngeprint suatu node, maka head akan berpindah ke node selanjutnya;
    }
    //mengapa tidak mengembalikan posisi head ke node terbaru?
    //karena pada main head akan di null kan
}

void hapus(Mahasiswa** head){
    Mahasiswa* current = *head;
    //untuk menggantikan head agar head tidak berpindah
    while(current != NULL){
        Mahasiswa* temp = current;
        //dibuat dua, dikarenakan current akan berfungsi ke node selanjutnya
        //dan temp berfungsi untuk menghapus node
        current = current->link;
        free(temp);
    }
    *head = NULL;
}

void hapus1(Mahasiswa** head){
    if(*head == NULL){
        printf("Tidak ada linked list\n");
        return;
    }
    Mahasiswa* temp = *head;
    //untuk menggantikan head agar tidak dihapus
    *head = temp->link;
    //head pindah ke node selanjutnya
    free(temp);
    //temp dihilangkan

    //sehingga posisi akhir = temp head node3 node4...
    //temp dihapus menyisakan = head node3 node4...
}

void hapusnim(Mahasiswa** head, int nim){
    if(*head == NULL){
        printf("Tidak ada linked list\n");
        return;
    }
    Mahasiswa* current = *head;
    //untuk menggantikan head
    Mahasiswa* previous = NULL;
    //digunakan agar prev tidak menempel pada node

    if(current != NULL && current->nim == nim){
        //jika saat current = head, ternyata nim ada di head
        *head = current->link;
        //head dipindahkan ke node selanjutnya
        free(current);
        //current tersebut akan dihapus sehingga head akan tetap di posisi pertama
        return;
    }

    while(current != NULL && current->nim != nim){
        //proses pencarian nim
        previous = current;
        current = current->link;

        //posisi akhir = previous current node3 node4...
    }

    if(current != NULL){
        //ketika menemukan nim
        //hal ini dikarenakan proses while sebelumnya akan terhenti
        //jika nim ditemukan
        //semisal while terus-menerus bekerja dan nim yang dicari tidak ada
        //maka tahap ini akan dilewati karena current == while
        previous->link = current->link;
        //si previous akan bersama current
        //posisi akhir = noden current&previous noden+2...
        free(current);
        //current dan previous hilang
        return;
    }

    printf("NIM tidak ditemukan pada linked list\n");
    //jika nim tidak ditemukan, maka akan tertulis seperti ini
    //dikarenakan pada if sebelumnya ada return
    //sehingga tidak akan ke printf
}


int main(){

    Mahasiswa* head = NULL;
    int pilihan, nim;
    do {
        printf("1. Insert new node\n2. Print linked list\n3. Delete all data\n4. Delete first data\n4. Delete first data\n5. Delete data by NIM\n6. Exit\nPilihan: ");
        scanf("%d", &pilihan);

        switch(pilihan){
            case 1:
                buatbaru(&head);
                printf("\n");
                break;
            case 2:
                ngeprint(head);
                printf("\n");
                break;
            case 3:
                hapus(&head);
                printf("\n");
                break;
            case 4:
                hapus1(&head);
                printf("\n");
                break;
            case 5:
                printf("NIM\t: ");
                scanf("%d", &nim);
                hapusnim(&head, nim);
                printf("\n");
                break;
            case 6:
                exit(0);
            default:
                break;
        }

    } while(pilihan != 6);
}
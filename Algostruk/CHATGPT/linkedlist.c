#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa {
    char nama[50];
    char jurusan[50];
    char nim[20];
    struct Mahasiswa* next;
} Mahasiswa;

void tambahMahasiswa(Mahasiswa** head) {
    Mahasiswa* newMahasiswa = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    printf("Masukkan nama: ");
    scanf("%s", newMahasiswa->nama);
    printf("Masukkan jurusan: ");
    scanf("%s", newMahasiswa->jurusan);
    printf("Masukkan NIM: ");
    scanf("%s", newMahasiswa->nim);
    newMahasiswa->next = *head;
    *head = newMahasiswa;
    printf("Mahasiswa berhasil ditambahkan.\n");
}

void cetakMahasiswa(Mahasiswa* head) {
    if (head == NULL) {
        printf("Linked list kosong.\n");
        return;
    }
    printf("Linked list Mahasiswa:\n");
    while (head != NULL) {
        printf("Nama: %s\n", head->nama);
        printf("Jurusan: %s\n", head->jurusan);
        printf("NIM: %s\n\n", head->nim);
        head = head->next;
    }
}

void hapusSemuaMahasiswa(Mahasiswa** head) {
    Mahasiswa* current = *head;
    Mahasiswa* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
    printf("Semua data Mahasiswa berhasil dihapus.\n");
}

void hapusMahasiswaPertama(Mahasiswa** head) {
    if (*head == NULL) {
        printf("Linked list kosong.\n");
        return;
    }
    Mahasiswa* temp = *head;
    *head = temp->next;
    free(temp);
    printf("Data Mahasiswa pertama berhasil dihapus.\n");
}

void hapusMahasiswaByNIM(Mahasiswa** head, char nim[20]) {
    Mahasiswa* current = *head;
    Mahasiswa* prev = NULL;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->nim, nim) == 0) {
            found = 1;
            break;
        }
        prev = current;
        current = current->next;
    }
    if (found) {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        printf("Data Mahasiswa dengan NIM %s berhasil dihapus.\n", nim);
    } else {
        printf("Data Mahasiswa dengan NIM %s tidak ditemukan.\n", nim);
    }
}

int main() {
    Mahasiswa* head = NULL;
    int opsi;
    char nim[20];
    while (1) {
        printf("Menu:\n");
        printf("1. Tambah data Mahasiswa\n");
        printf("2. Cetak data Mahasiswa\n");
        printf("3. Hapus semua data Mahasiswa\n");
        printf("4. Hapus data Mahasiswa pertama\n");
        printf("5. Hapus data Mahasiswa berdasarkan NIM\n");
        printf("6. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &opsi);

        switch (opsi) {
        case 1:
            tambahMahasiswa(&head);
            break;
        case 2:
            cetakMahasiswa(head);
            break;
        case 3:
            hapusSemuaMahasiswa(&head);
            break;
        case 4:
            hapusMahasiswaPertama(&head);
            break;
        case 5:
            printf("Masukkan NIM yang ingin dihapus: ");
            scanf("%s", nim);
            hapusMahasiswaByNIM(&head, nim);
            break;
        case 6:
            hapusSemuaMahasiswa(&head);
            exit(0);
        default:
            printf("Opsi tidak valid.\n");
        }
    }
return 0;
}

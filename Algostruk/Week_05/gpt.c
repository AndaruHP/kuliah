#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struktur untuk node pada double linked list
struct node {
    char singer[50];
    char album[50];
    char song[50];
    int year;
    struct node* prev;
    struct node* next;
};

// fungsi untuk membuat node baru pada double linked list
struct node* createNode(char singer[], char album[], char song[], int year) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    strcpy(newNode->singer, singer);
    strcpy(newNode->album, album);
    strcpy(newNode->song, song);
    newNode->year = year;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// fungsi untuk menambahkan node baru pada double linked list
void addNode(struct node** headRef, char singer[], char album[], char song[], int year) {
    struct node* newNode = createNode(singer, album, song, year);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct node* currNode = *headRef;
    while (currNode->next != NULL) {
        currNode = currNode->next;
    }
    currNode->next = newNode;
    newNode->prev = currNode;
}

// fungsi untuk menghapus node pada double linked list
void deleteNode(struct node** headRef, struct node* delNode) {
    if (*headRef == NULL || delNode == NULL) {
        return;
    }
    if (*headRef == delNode) {
        *headRef = delNode->next;
    }
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    free(delNode);
}

// fungsi untuk membaca data dari file.txt dan membuat double linked list
void readFile(struct node** headRef) {
    FILE* fp = fopen("file.txt", "r");
    if (fp == NULL) {
        printf("File tidak ditemukan.\n");
        return;
    }
    char buffer[200];
    while (fgets(buffer, 200, fp)) {
        char* singer = strtok(buffer, "*");
        char* album = strtok(NULL, "*");
        char* song = strtok(NULL, "*");
        int year = atoi(strtok(NULL, "*"));
        addNode(headRef, singer, album, song, year);
    }
    fclose(fp);
}

// fungsi untuk menuliskan data dari double linked list ke file.txt
void writeFile(struct node* head) {
    FILE* fp = fopen("file.txt", "w");
    if (fp == NULL) {
        printf("File tidak dapat dibuka.\n");
        return;
    }
    struct node* currNode = head;
    while (currNode != NULL) {
        fprintf(fp, "%s*%s*%s*%d\n", currNode->singer, currNode->album, currNode->song, currNode->year);
        currNode = currNode->next;
    }
    fclose(fp);
}

// fungsi untuk menampilkan data pada double linked list
void printList(struct node* head) {
    if (head == NULL) {
        printf("Double linked list kosong.\n");
        return;
    }

    printf("Daftar lagu:\n");
    struct node* currNode = head;
    while (currNode != NULL) {
        printf("Penyanyi: %s, Album: %s, Lagu: %s, Tahun: %d\n", currNode->singer, currNode->album, currNode->song, currNode->year);
        currNode = currNode->next;
    }
}

int main() {
    struct node* head = NULL;
    readFile(&head);

    int choice;
    do {
        printf("Menu:\n");
        printf("1. Tampilkan data\n");
        printf("2. Tambah data\n");
        printf("3. Hapus data\n");
        printf("4. Exit\n");
        printf("Pilih: ");
        scanf("%d", &choice);
        getchar(); // membersihkan newline pada stdin

        switch (choice) {
            case 1:
                printList(head);
                break;
            case 2:
                printf("Masukkan nama penyanyi: ");
                char singer[50];
                fgets(singer, 50, stdin);
                singer[strcspn(singer, "\n")] = 0; // menghapus newline pada input
                printf("Masukkan nama album: ");
                char album[50];
                fgets(album, 50, stdin);
                album[strcspn(album, "\n")] = 0;
                printf("Masukkan nama lagu: ");
                char song[50];
                fgets(song, 50, stdin);
                song[strcspn(song, "\n")] = 0;
                printf("Masukkan tahun: ");
                int year;
                scanf("%d", &year);
                getchar(); // membersihkan newline pada stdin
                addNode(&head, singer, album, song, year);
                writeFile(head);
                printf("Data berhasil ditambahkan.\n");
                break;
            case 3:
                printf("Masukkan nama penyanyi: ");
                char singerToDelete[50];
                fgets(singerToDelete, 50, stdin);
                singerToDelete[strcspn(singerToDelete, "\n")] = 0;
                struct node* currNode = head;
                while (currNode != NULL) {
                    if (strcmp(currNode->singer, singerToDelete) == 0) {
                        deleteNode(&head, currNode);
                        writeFile(head);
                        printf("Data berhasil dihapus.\n");
                        break;
                    }
                    currNode = currNode->next;
                }
                if (currNode == NULL) {
                    printf("Data tidak ditemukan.\n");
                }
                break;
            case 4:
                printf("Terima kasih telah menggunakan program ini.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 4);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct Mahasiswa{
    char nama[100];
    char jurusan[30];
    int nim;
    struct Mahasiswa *next;
} Mahasiswa;

Mahasiswa *createNewNode(int nim, char *nama, char *jurusan){
    Mahasiswa *newNode = (Mahasiswa*) malloc (sizeof(Mahasiswa));
    newNode->nim = nim;
    strcpy(newNode->nama, nama);
    strcpy(newNode->jurusan, jurusan);
    newNode->next = NULL;
    return newNode;
}

void printLinkedList(Mahasiswa *head){
    Mahasiswa *temp;

    temp = head;
    int i = 1;
    while(temp != NULL){
        printf("Data ke %d\nNIM\t: %d\nNama\t: %s\nJurusan\t: %s\n\n", i, temp->nim, temp->nama, temp->jurusan);
        temp = temp->next;
        i++;
    }
}

int main(){
    Mahasiswa *head, *node;
    head = NULL;
    node = (Mahasiswa*) malloc(sizeof(Mahasiswa));
    node->nim = 14026;
    strcpy(node->nama, "James Christian Wira");
    strcpy(node->jurusan, "Informatika");   
    head = node;

    Mahasiswa *tail;
    tail = node;

    node = createNewNode(17492, "Matther Evans", "Informatika");

    tail->next = node;
    tail = node;

    node = createNewNode(13633, "Justin Susanto", "Informatika");
    node->next = head;
    head = node;

    printLinkedList(head);
}
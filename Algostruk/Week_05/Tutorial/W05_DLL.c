#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct Mahasiswa {
    char nama[100];
    char jurusan[30];
    int nim;
    struct Mahasiswa *next, *prev;
} Mahasiswa;

void createnewmode(int nim, char *nama, char *jurusan, Mahasiswa **tail){
    Mahasiswa *newnode = (Mahasiswa*) malloc (sizeof(Mahasiswa));
    newnode->nim = nim;
    strcpy(newnode->nama, nama);
    strcpy(newnode->jurusan, jurusan);
    newnode->next = NULL;

    newnode->prev = *tail;
    (*tail)->next = newnode;
    *tail = newnode;
}

void printlinkedlist(Mahasiswa **head){
    Mahasiswa *temp;
    temp = *head;
    int i = 1;
    while(temp != NULL){
        printf("Data ke %d\nNIM\t: %s\nNama\t: %s\n\n", temp->nim, temp->nama, temp->jurusan);
        temp = temp->next;
        i++;
    }
}

void headdeletion(Mahasiswa **head){
    Mahasiswa *trash = *head;
    *head = trash->next;
    (*head)->prev = NULL;
    trash->next = NULL;
    free(trash);
}

void taildeletion(Mahasiswa **tail){
    Mahasiswa *trash = *tail;
    *tail = trash->prev;
    (*tail)->next = NULL;
    trash->prev = NULL;
    free(trash);
}

void middledeletion(Mahasiswa **head, int target){
    Mahasiswa *trash = *head, *tempbefore, *tempafter;
    while(trash->nim != target){
        trash = trash->next;
    }

    tempbefore = trash->prev;
    tempafter = trash->next;

    tempbefore->next = NULL;
    tempafter->next = NULL;
    free(trash);
}

int main(){
    Mahasiswa *head, *node, *tail;
    head = tail = NULL;

    node = (Mahasiswa*) malloc (sizeof(Mahasiswa));
    node->nim = 12345;
    strcpy(node->nama, "James Charles");
    strcpy(node->jurusan, "informatika");

    node->next = node->prev = NULL;
    head = node;
    tail = node;

    node = (Mahasiswa*) malloc (sizeof(Mahasiswa));
    node->nim = 11111;
    strcpy(node->nama, "James Dicky");
    strcpy(node->jurusan, "DKV");
    node->next = NULL;

    node->prev = tail;
    tail->prev = node;
    tail = node;
    createnewmode(10902, "James Clear", "Informatika", &tail);
    createnewmode(10903, "James E", "Informatika", &tail);
    createnewmode(10904, "James R", "Informatika", &tail);
    createnewmode(10905, "James T", "Informatika", &tail);
    createnewmode(10906, "James C", "Informatika", &tail);
    createnewmode(10907, "James A", "Informatika", &tail);
    createnewmode(10908, "James Z", "Informatika", &tail);

    printf("All data inside linked list\n");
    printlinkedlist(head);

    printf("All data after 2x head deletion\n");
    headdeletion(&head);
    headdeletion(&head);

    printf("All data after 1x tail deletion\n");
    taildeletion(&tail);
    printlinkedlist(head);

    printf("All data after middle deletion (James E - 10903)");
    middledeletion(&head, 10903);
    printlinkedlist(head);
}



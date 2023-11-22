#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef struct Mahasiswa{
    char nim[15];
    char nama[50];
    char jurusan[30];
    struct Mahasiswa *next;
} Mahasiswa;

int isEmpty(Mahasiswa *queue){
    if(queue == NULL) return 1;
    return 0;
}

void enqueue(Mahasiswa **head, Mahasiswa **tail, char nim[], char nama[], char jurusan[]){
    Mahasiswa *data = (Mahasiswa*) malloc (sizeof(Mahasiswa));
    strcpy(data->nim, nim);
    strcpy(data->nama, nama);
    strcpy(data->jurusan, jurusan);
    data->next = NULL;

    if(isEmpty(*head)) *head = data;
    else (*tail)->next = data;
    *tail = data;
    printf("Adding %s to queue\n", nama);
}

void dequeue(Mahasiswa **head){
    printf("Removing queue's front element\n");
    if(isEmpty(*head)){
        printf("Nothing to dequeue. Queue already empty\n");
        return;
    }

    Mahasiswa *trash = *head;
    *head = trash->next;
    free(trash);
    printf("Dequeueing success\n");
}

Mahasiswa *front(Mahasiswa *queue){
    if(queue = NULL) return NULL;
    return queue;
}

int main(){
    printf("Queue Tutorial\n");
    printf("--------------\n\n");

    printf("Initializing Queue\n\n");
    Mahasiswa *headQueue, *tailQueue;
    headQueue = tailQueue = NULL;

    printf("Is Queue empty? %s\n", isEmpty(headQueue) ? "Yes" : "No");
    printf("What is the name at the front? %s\n\n", front(headQueue) == NULL ? "No one. Queue is empty" : front(headQueue)->nama);

    enqueue(&headQueue, &tailQueue, "12345", "Nama1", "Jurusan1");
    printf("What is the name at the front? %s\n\n", front(headQueue) == NULL ? "No one. Queue is empty" : front(headQueue)->nama);
    printf("Is Queue empty? %s\n", isEmpty(headQueue) ? "Yes" : "No");

    dequeue(&headQueue);
    printf("Is Queue empty? %s\n", isEmpty(headQueue) ? "Yes" : "No");
    printf("What is the name at the front? %s\n\n", front(headQueue) == NULL ? "No one. Queue is empty" : front(headQueue)->nama);

    enqueue(&headQueue, &tailQueue, "12346", "Nama2", "Jurusan2");
    enqueue(&headQueue, &tailQueue, "12347", "Nama3", "Jurusan3");
    enqueue(&headQueue, &tailQueue, "12348", "Nama4", "Jurusan4");
    printf("What is the name at the front? %s\n\n", front(headQueue) == NULL ? "No one. Queue is empty" : front(headQueue)->nama);
    printf("Is Queue empty? %s\n", isEmpty(headQueue) ? "Yes" : "No");

    dequeue(&headQueue);
    printf("What is the name at the front? %s\n\n", front(headQueue) == NULL ? "No one. Queue is empty" : front(headQueue)->nama);

    dequeue(&headQueue);
    printf("What is the name at the front? %s\n\n", front(headQueue) == NULL ? "No one. Queue is empty" : front(headQueue)->nama);

    dequeue(&headQueue);
    printf("\n");
    dequeue(&headQueue);
    return 0;
}
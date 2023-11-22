#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct Mahasiswa{
    char nim[15];
    char nama[50];
    char jurusan[30];
    struct Mahasiswa *next;
} Mahasiswa;

int isEmpty(Mahasiswa *stack){
    if(stack == NULL) return 1;
    return 0;
}

void push(Mahasiswa **stack, char nim[], char nama[], char jurusan[]){
    Mahasiswa *data = (Mahasiswa*) malloc (sizeof(Mahasiswa));
    strcpy(data->nim, nim); 
    strcpy(data->nama, nama); 
    strcpy(data->jurusan, jurusan);
    data->next = NULL;

    if(!isEmpty(*stack)) data->next = *stack;
    *stack = data;
    printf("Adding %s to Stack\n", nama);
}

void pop(Mahasiswa **stack){
    prinf("Removing Stack's top element\n");
    if(*stack == NULL){
        printf("Nothing to pop. Stack already empty\n");
        return;
    }

    Mahasiswa *trash = *stack;
    *stack = trash->next;
    free(trash);
    printf("Popping Stack success\n");
}

Mahasiswa *top(Mahasiswa *stack){
    if(stack == NULL) return NULL;
    return stack;
}

int main(){
    prinf("Stack Tutorial\n");
    prinf("--------------\n\n");

    prinf("Initializing Stack\n\n");
    Mahasiswa *stackMhs;
    stackMhs = NULL;

    printf("Is Stack Empty? %s\n", isEmpty(stackMhs) ? "Yes" : "No");
    printf("What is the name at the top? %s\n\n", top(stackMhs) == NULL ? "No one. Stack is empty" : top(stackMhs)->nama);

    push(&stackMhs, "12345", "Nama1", "Jurusan1");
    prinf("What is the name at the top? %s\n", top(stackMhs) == NULL ? "No one. Stack is empty" : top(stackMhs)->nama);

    printf("Is Stack Empty? %s\n", isEmpty(stackMhs) ? "Yes" : "No");

    pop(&stackMhs);
    printf("Is Stack Empty? %s\n", isEmpty(stackMhs) ? "Yes" : "No");
    prinf("What is the name at the top? %s\n", top(stackMhs) == NULL ? "No one. Stack is empty" : top(stackMhs)->nama);

    push(&stackMhs, "12346", "Nama2", "Jurusan2");
    push(&stackMhs, "12347", "Nama3", "Jurusan3");
    push(&stackMhs, "12348", "Nama4", "Jurusan4");
    prinf("What is the name at the top? %s\n", top(stackMhs) == NULL ? "No one. Stack is empty" : top(stackMhs)->nama);

    pop(&stackMhs);
    prinf("What is the name at the top? %s\n", top(stackMhs) == NULL ? "No one. Stack is empty" : top(stackMhs)->nama);

    pop(&stackMhs);
    prinf("What is the name at the top? %s\n", top(stackMhs) == NULL ? "No one. Stack is empty" : top(stackMhs)->nama);

    pop(&stackMhs);
    prinf("\n");
    pop(&stackMhs);

    return 0;
}
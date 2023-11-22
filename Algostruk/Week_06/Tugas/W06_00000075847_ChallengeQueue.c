#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
//akan menjadikan sebuah node memiliki int data dan akan menjadikannya single linked list

void enqueue(Node** front, Node** rear, int value);
void dequeue(Node** front);
int getFront(Node* front);
void printQueue(Node* front);

int main() {
    Node* front = NULL;
    Node* rear = NULL;
    //node front merupakan pointer elemen pertama dan rear merupakan pointer elemen terakhir

    int input;
    while (1) {
        printf("Enter a number: ");
        scanf("%d", &input);

        if (front == NULL) {
            //kalo masih kosong
            for (int i = 0; i < input; i++) {
                enqueue(&front, &rear, input);
            }
            printQueue(front);
            //bakal print semua data yang tersimpan
        }
        else if (input < getFront(front)) {
            //kalo udah ada isinya tapi nilai dari input kita lebih kecil dari data sebelumnya
            for (int i = 0; i < input; i++) {
                dequeue(&front);
            }
            printQueue(front);
        }
        else {
            int frontVal = getFront(front);
            //kalo si input lebih besar dari nilai front maka akan menggunakan front
            for (int i = 0; i < frontVal; i++) {
                enqueue(&front, &rear, input);
            }
            printQueue(front);
        }
    }
    return 0;
}

void enqueue(Node** front, Node** rear, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    //data dari node baru adalah input
    newNode->next = NULL;
    //next dari node tersebut masih kosong

    if (*front == NULL) {
        *front = *rear = newNode;
        //kalo bener-bener masih baru maka head = tail
    }
    else {
        (*rear)->next = newNode;
        *rear = newNode;
        //akan membuat node baru dan menempatkan tail pada node baru tersebut
    }
}

void dequeue(Node** front) {
    if (*front == NULL) {
        printf("The queue is empty! Nothing to dequeue!\n");
        return;
    }

    Node* temp = *front;
    *front = (*front)->next;
    free(temp);
}

int getFront(Node* front) {
    if (front == NULL) {
        return -1;
        //jika nilai paling depan tidak ditemukan akan return -1
    }

    return front->data;
    //untuk mencari nilai terdepan
}

void printQueue(Node* front) {
    if (front == NULL) {
        printf("The queue is empty now.\n");
        return;
    }

    Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        //ngeprint sampai semua linked list habis alias null
    }
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
//kapasitas maksimum dari stack tersebut adalah 100 (isi)

typedef struct {
    char data[MAX_STACK_SIZE];
    int top;
} Stack;
//seperti pada linked list, top = head dan char adalah sebuah array

void initialize(Stack *stack);
int isFull(Stack *stack);
int isEmpty(Stack *stack);
void push(Stack *stack, char c);
char pop(Stack *stack);
int checkParenthesis(char *str);

int main() {
    char str[100];
    printf("Masukan pola: ");
    fgets(str, sizeof(str), stdin);
    //memasukkan string
    if (checkParenthesis(str)) {
        //cek dulu ke fungsi checkParenthesis
        printf("Valid parenthesis expression\n");
    } else {
        printf("Invalid parenthesis expression\n");
    }
    return 0;
}

void initialize(Stack *stack) {
    stack->top = -1;
}
//mengatur agar nilai dari top adalah -1

int isFull(Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}
//fungsi ini berfungsi untuk mengecek apakah stack sudah penuh atau belum
//pada hal ini, jika true maka akan memberikan nilai 1 dan jika salah mengeluarkan nilai 0

int isEmpty(Stack *stack) {
    return stack->top == -1;
}
//sama seperti isFull

void push(Stack *stack, char c) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack->data[++stack->top] = c;
}
//fungsi untuk memasukkan data ke stack, saat isFull bernilai truw maka akan mencetak Stack overflow
//dan akan langsung keluar dari fungsi tanpa lanjut ke perintah selanjutnya
//stack->data[++stack->top] = c dapat dipecah menjadi
//stack->top = stack->top + 1 nilai dari top akan ditambahkan 1 dikarenakan data bertambah maka posisi top berubah
//selanjutnya stack->data[x] merupakan data ke [stack->top = stack->top + 1] == input[x]
//seperti yang kita tahu kita input sebauh string dan string tersebut dipecah menjadi beberapa char


char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack->data[stack->top--];
}


int checkParenthesis(char *str) {
    Stack stack;
    initialize(&stack);
    //posisi top = -1
    int len = strlen(str);
    //ubah ke variabel baru
    int i;
    for (i = 0; i < len; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(&stack, str[i]);
            //kalo memenuhi maka akan dimasukkan ke dalam stack 
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            //kalo selain yang diinginkan maka akan...
            if (isEmpty(&stack)) {
                //jika ditemukan penutup kurung di awal alias saat empty maka akan return = 0
                //jika return = 0 maka akan mengembalikan nilai false dan print invalid parenthesis expression
                return 0;
            } else {
                char top = pop(&stack);
                //mengambil buka kurung terakhir dalam stack
                if ((str[i] == ')' && top != '(') || (str[i] == ']' && top != '[') || (str[i] == '}' && top != '{')) {
                    //cek apakah itu array yang diperiksa sesuai dengan top terakhir
                    return 0;
                }
            }
        }
    }
    return isEmpty(&stack);
    //kalo udah kosong berarti true
}
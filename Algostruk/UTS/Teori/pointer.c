#include<stdio.h>
#include<stdlib.h>

int global;

void bla(){
    int lokal;
}

int main(){
    int arr[3] = {1, 5, 4};
    int lokal;
    printf("%d\n", arr[0]);
    printf("%p\n", &arr[0]);
    printf("%p\n", &arr[1]);
    printf("%p\n", &arr[2]);
    printf("%p\n", &arr);
    printf("%p\n", arr);


}
#include<stdio.h>

int main(){
    int n;
    int sum = 0;
    do{
        printf("Masukkan harga barang : ");
        scanf("%d", &n);
        sum += n;
    } while(n != -1);
    printf("Total Harga : %d", sum + 1);
}


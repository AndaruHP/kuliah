#include<stdio.h>

int main(){
    char a[1];
    char b[4];
    char c[4];
    printf("Plat nomor: ");
    scanf("%c %s %s", &a, &b, &c);
    fflush(stdin);
    printf("Kota: %c\nNo. Kendaraan: %s\nPemilik: %s", a, b, c);
}

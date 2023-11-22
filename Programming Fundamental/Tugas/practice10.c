#include<stdio.h>

int main(){
    char nama[20];
    int angka;
    printf("Input: ");
    scanf("%[^#]#%d", &nama, &angka);
    printf("ID\t: %s%d\n", "000000", angka);
    printf("Nama\t: %s", nama);
}

/*
    1. 000387.4
    2. __153__27
    3. __93.24422__53
    4. __8_3119
    5. 15 031 0x23
    6. X_90
    7. au
    8.
    */

    /* 6.
    int a = 88;
    putchar(a++); //si a bakal nambah tapi di putchar belum tertulis tapi a jadi 89
    printf("%3d", ++a);
    */
    /*
    char nama[20];
    int nim;
    scanf("%[^#]s#%5d", &nama, &nim);
    printf("ID: %s%d\n", "000000", nim);
    printf("Name : %s", nama);
    */

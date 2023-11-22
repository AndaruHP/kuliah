#include<stdio.h>
int main(){
    printf("Hi Student!!!\n");
    printf("Input Your Name: ");
    char nama[20];
    gets(nama);

    printf("\n\n\n##################\n\n\n");

    printf("Hi %s\n\n", nama);
    printf("Menu:\n1. Penjumlalhan\n2. Pengurangan\n3. Perkalian\n4. Pembagian\n5. Exit\n\n");

    printf("\n\n\n##################\n\n\n");

    float a, b;
    int option;
    printf("Input Number 1: ");
    scanf("%f", &a);
    do{
        printf("Input Number 2: ");
        scanf("%f", &b);
    } while(b == 0);
    printf("Input Menu: ");
    scanf("%d", &option);


    float ans;

    switch(option){
        case 1:
            ans = a + b;
            printf("Hasil Penjumlahan = %f", ans);
            break;
        case 2:
            if(a > b){
                ans = a - b;
            } else {
                ans = b - a;
            }
            printf("Hasil Pengurangan = %f", ans);
            break;
        case 3:
            ans = a*b;
            printf("Hasil Perkalian = %f", ans);
            break;
        case 4:
            ans = a/b;
            printf("Hasil Pembagian = %f", ans);
            break;
        case 5:
            printf("\nThank You, Have a Nice Day!!");
            break;
    }

}

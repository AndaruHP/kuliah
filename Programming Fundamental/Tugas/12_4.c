#include<stdio.h>

int main(){
    float a, b;

    printf("Menu\n1. Pengurangan\n2. Pembagian\n3. Exit");
    int option;
    printf("\nMasukkan Pilihan Anda: ");
    scanf("%d", &option);



    float ans;
    switch(option){
    case 1:
        printf("\n\n\n");
        printf("angka1 : ");
        scanf("%f", &a);
        printf("angka2 : ");
        scanf("%f", &b);
        if(a > b){
            ans = a - b;
        } else {
            ans = b - a;
        }
        printf("Hasil : %f", ans);
        break;

    case 2:
        printf("\n\n\n");
        printf("angka1 : ");
        scanf("%f", &a);
        do{
            printf("angka2 : ");
            scanf("%f", &b);
        } while(b == 0);
        ans = a/b;
        printf("Hasil : %f", ans);
        break;

    case 3:
        break;
    }


}

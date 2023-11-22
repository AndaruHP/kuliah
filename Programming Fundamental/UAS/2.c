#include<stdio.h>

int phi = 3.14;

int main(){
    int option, i;
    float x, kll, luas;

    do {
        printf("1. Rectangle\n2. Triangle\n3. Circle\n");
        printf("Pilih Menu : ");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Input Sisi : ");
                scanf("%f", &x);
                //check pake /10
                int check = sizeof(x);
                for(int j = 0; j < check; j++){
                    if(x[j] >= 1 && x[j] <= 9){
                        kll = 4 * x;
                        luas = x * x;
                        printf("Keliling = %f\n", kll);
                        printf("Luas = %f\n", luas);
                        break;
                    } else {
                        pritnf("Ada Kesalahan Pada Input Nilai");
                        break;
                    }
                }
            case 2:
                printf("Input Sisi : ");
                scanf("%f", &x);


                kll = 3 * x;
                luas = x * x / 2;
                printf("Keliling = %f\n", kll);
                printf("Luas = %f\n", luas);
                break;
            case 3:
                printf("Input Jari-jari : ");
                scanf("%f", &x);


                kll = 2 * phi * x;
                luas = phi * x * x;
                printf("Keliling = %f\n", kll);
                printf("Luas = %f\n", luas);
                break;
            default:
                break;
        }
        printf("\n\n=============\n\n\n");
    } while(option == 1 || option == 2 || option == 3);

    printf("Selesai.\nTerimakasih.");
}

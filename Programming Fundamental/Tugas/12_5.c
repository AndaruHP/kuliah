#include<stdio.h>

int main(){
    char pemenang[5];
    int option;
    do{
        printf("Selamat Datang di WinWin Doorprize\n");
        printf("Pengambilan hadiah dapat dilakukan dengan menunjukan No_IDCard\n\n");
        printf("Menu\n1. Ambil Hadiah\n2. Info Pemenang dan Hadiah\n3. Exit");
        printf("\nPilihan Anda : ");
        scanf("%d", &option);

        switch(option){
        case 1:
            printf("Masukan No IDCard : ");
            scanf("%s", pemenang);
            if(strcmp(pemenang, "0001A") == 0){
                printf("Selamat Anda memenangkan hadiah kulkas");
            } else if(strcmp(pemenang, "0001B") == 0){
                printf("Selamat Anda memenangkan hadiah TV");
            } else if(strcmp(pemenang, "0001C") == 0){
                printf("Selamat Anda memenangkan hadiah Smartphone");
            } else {
                printf("Maaf Anda Belum Beruntung");
            }
            printf("\nTekan untuk keluar");
            getch();
            system("cls");
            break;
        case 2:
            printf("Pemenang 1 : Budi : kulkas\nPemenang 2 : Alex : TV\nPemenang 3 : Sander : Smartphone");
            printf("\nTekan untuk keluar");
            getch();
            system("cls");
            break;
        }
    } while(option != 3);
    system("cls");
    printf("Have a nice day!!");
    return 0;

}


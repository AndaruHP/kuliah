#include<stdio.h>
#include<time.h>
#include<string.h>

struct data{
    char platnomor[10];
    char time1[1024];
    char time2[1024];
};

int option(){
    int option;
    printf("Selamat Datang di ParkIn\n");
    printf("========================\n");
    printf("1. Check In\n2. Check Out\n3. Tampilkan Data\n4. Exit\n");
    printf("Pilihan Anda: ");
    scanf("%d", &option);
    return option;
}

int pilihkendaraan(){
    system("cls");
    printf("Pilih Jenis Kendaraan Anda\n");
    printf("========================\n");
    printf("1. Motor\n2. Mobil\n");
    printf("========================\n");
    printf("Pilihan Anda: ");
    int option;
    scanf("%d", &option);
    return option;
}

int timenow(){
    time_t now = time(NULL);
    char *time_now = ctime(&now);
    struct tm *gm_time = gmtime(&now);

    int time1 = (gm_time -> tm_sec);
    return time1;
}

int price1(int a, int b){
    //Biaya 100 perdetik
    return (b - a) * 10;
}

int price2(int a, int b){
    //Biaya 100 perdetik
    return (b - a) * 20;
}

void checkmotor(){
    FILE *fp, *fp1;
    fp = fopen("motor.txt", "r");
    if(fp != NULL){
        fclose(fp);
    } else {
        fclose(fp);
        fp = fopen("motor.txt", "a+");
        fclose(fp);
    }
    fp1 = fopen("temp1.txt", "r");
    if(fp != NULL){
        fclose(fp1);
    } else {
        fclose(fp1);
        fp1 = fopen("temp1.txt", "a+");
        fclose(fp1);
    }
}

void checkmobil(){
    FILE *fp, *fp1;
    fp = fopen("mobil.txt", "r");
    if(fp != NULL){
        fclose(fp);
    } else {
        fclose(fp);
        fp = fopen("mobil.txt", "a+");
        fclose(fp);
    }
    fp1 = fopen("temp2.txt", "r");
    if(fp != NULL){
        fclose(fp1);
    } else {
        fclose(fp1);
        fp1 = fopen("temp2.txt", "a+");
        fclose(fp1);
    }
}

void motor(){
    FILE *fp;
    fp = fopen("motor.txt", "a+");
    struct data x;
    printf("Masukkan Plat: ");
    scanf("%s", &x.platnomor);

    time_t now = time(NULL);
    char *string_now = ctime(&now);
    strcpy(x.time1, string_now);

    fwrite(&x, sizeof(x), 1, fp);
    fclose(fp);
}

void mobil(){
    FILE *fp;
    fp = fopen("mobil.txt", "a+");
    struct data x;
    printf("Masukkan Plat: ");
    scanf("%s", &x.platnomor);

    time_t now = time(NULL);
    char *string_now = ctime(&now);
    strcpy(x.time1, string_now);

    fwrite(&x, sizeof(x), 1, fp);
    fclose(fp);
}

void motorout(){
    struct data z;
    FILE *fp, *fp1;
    int found = 0;
    char ans[10];
    fp = fopen("motor.txt", "r");
    fp1 = fopen("temp1.txt", "w");
    printf("\nPlat nomor: ");
    scanf("%s", &ans);
    while(fread(&z, sizeof(struct data), 1, fp)){
        if(strcmp(z.platnomor, ans) == 0){
            found = 1;
        } else {
            fwrite(&z, sizeof(struct data), 1, fp1);
        }
    }
    fclose(fp1);
    fclose(fp);

    if(found){
        fp1 = fopen("temp1.txt", "r");
        fp = fopen("motor.txt", "w");

        while(fread(&z, sizeof(z), 1, fp1)){
            fwrite(&z, sizeof(z), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
    } else {
        printf("\nData doesn't exist");
    }
}

void mobilout(){
     struct data z;
    FILE *fp, *fp1;
    int found = 0;
    char ans[10];
    fp = fopen("mobil.txt", "r");
    fp1 = fopen("temp2.txt", "w");
    printf("\n Plat nomor: ");
    scanf("%s", &ans);
    while(fread(&z, sizeof(struct data), 1, fp)){
        if(strcmp(z.platnomor, ans) == 0){
            found = 1;
        } else {
            fwrite(&z, sizeof(struct data), 1, fp1);
        }
    }
    fclose(fp1);
    fclose(fp);

    if(found){
        fp1 = fopen("temp2.txt", "r");
        fp = fopen("mobil.txt", "w");

        while(fread(&z, sizeof(z), 1, fp1)){
            fwrite(&z, sizeof(z), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
    } else {
        printf("\nData doesn't exist");
    }
}

void display1(){
    struct data y;
    FILE *fp;
    fp = fopen("motor.txt", "r");
    while(fread(&y, sizeof(y), 1, fp)){
        printf("\n%s\t\t", y.platnomor);
        printf("%s", &y.time1);
    }
    fclose(fp);
}

void display2(){
    struct data y;
    FILE *fp;
    fp = fopen("mobil.txt", "r");
    while(fread(&y, sizeof(y), 1, fp)){
        printf("\n%s\t\t", y.platnomor);
        printf("%s", &y.time1);
    }
    fclose(fp);
}

int main(){
    int pilihan, pilihan1, a, b, harga;
    char waktu[1024];
    do{
        pilihan = option();
        switch(pilihan){
        case 1:
            pilihan1 = pilihkendaraan();
            switch(pilihan1){
            case 1:
                checkmotor();
                motor();
                a = timenow();
                break;
            case 2:
                checkmobil();
                mobil();
                a = timenow();
                break;
            }
            break;
        case 2:
            pilihan1 = pilihkendaraan();
            switch(pilihan1){
            case 1:
                motorout();
                b = timenow();
                harga = price1(a, b);

                time_t now = time(NULL);
                char *string_now = ctime(&now);
                strcpy(waktu, string_now);
                printf("%s", waktu);
                printf("Total Biaya: %d\n", harga);
                printf("\nTap any key");
                getch();
                break;
            case 2:
                mobilout();
                b = timenow();
                harga = price2(a, b);
                printf("Total Biaya: %d\n", harga);
                printf("\nTap any key");
                getch();
                break;
            }
            break;
        case 3:
            pilihan1 = pilihkendaraan();
            switch(pilihan1){
            case 1:
                fflush(stdin);
                display1();
                printf("\nTap any key");
                getchar();
                break;
            case 2:
                fflush(stdin);
                display2();
                getchar();
                break;
            }
            break;
        }
        system("cls");
    } while(pilihan != 4);
}

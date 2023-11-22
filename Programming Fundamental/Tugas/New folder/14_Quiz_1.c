#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int x = 0;

struct data{
    char user[20];
    char pw[20];
};

void login(){
    char user[20];
    char pw[20];
    FILE *log;
    log = fopen("data.txt", "r");
    struct data a;
    printf("Log In\n");
    printf("Username: ");
    fflush(stdin);
    scanf("%s", &user);
    printf("Password: ");
    scanf("%s", &pw);
    fflush(stdin);

    //for(int i = 10; i <= sizeof(a); i = i + 10){
    while(fread(&a, sizeof(a), 1, log)){
        if(strcmp(user, a.user) == 0 && strcmp(pw, a.pw) == 0){
            printf("\nLogin Success");
        } else {
            printf("\nLogin Failed");
        }
    }
    //}
    fclose(log);
    getch();

}

void regis(){
    FILE *log;
    log = fopen("data.txt", "a+");
    struct data a;
    printf("Registration\n");
    printf("Username: ");
    scanf("%s", a.user);
    fflush(stdin);
    printf("Password: ");
    scanf("%s", a.pw);
    fflush(stdin);

    fwrite(&a, sizeof(a), 1, log);
    //fprintf(log, "\n");
    fclose(log);
    getch();
}


int main(){
    int option;

    do{
        system("cls");
        printf("1. Log In\n2. Register\n");
        printf("Press 3 to exit\n");
        scanf("%d", &option);
        switch(option){
        case 1:
            system("cls");
            login(x);
            break;
        case 2:
            system("cls");
            regis();
            //x++;
            break;
        default:
            break;
        }
    } while(option == 1 || option == 2);
    printf("Thank You");
}

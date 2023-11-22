#include<stdio.h>

int main(){
    char input[20];
    int i, nol = 0, satu = 0, dua = 0, tiga = 0;
    printf("Input password : ");
    scanf("%s", &input);

    for(i = 0; input[i] != '\0'; ++i); //input length

    //With ASCII

    for(int j = 0; j < i; j++){
        if(input[j] >= 65 && input[j] <= 90){
            satu++;
        }

        if(input[j] >= 97 && input[j] <= 122){
            dua++;
        }
        if(input[j] >= 48 && input[j] <= 57){
            tiga++;
        }
        if(!((input[j] >= 65 && input[j] <= 90) || (input[j] >= 97 && input[j] <= 122) || (input[j] >= 48 && input[j] <= 57))){
            nol++;
        }
    }
    if(nol == 0){
        if(satu == 0|| dua == 0 || tiga == 0){
            printf("Invalid");
        } else {
            printf("Valid");
        }
    } else {
        printf("Invalid");
    }


    /*
    if(input[0] >= 65 && input[0] <= 90){
        if(input[1] >= 97 && input[1] <= 122 && input[2] >= 97 && input[2] <= 122 && input[3] >= 97 && input[3] <= 122){
            if(input[4] >= 48 && input[4] <= 57 && input[5] >= 48 && input[5] <= 57 && input[6] >= 48 && input[6] <= 57 && input[7] >= 48 && input[7] <= 57){
                printf("Valid");
            } else {
                printf("Invalid");
            }
        } else {
            printf("Invalid");
        }
    } else {
        printf("Invalid");
    }
    */
}

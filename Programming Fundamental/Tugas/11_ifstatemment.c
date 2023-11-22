#include<stdio.h>
int main(){
    int nilai;
    scanf("%d", &nilai);

    /*
    if(nilai > 90){
        printf("Grade = A");
    } else if(nilai > 80 && nilai <= 90){
        printf("Grade = B");
    } else if(nilai > 70 && nilai <= 80){
        printf("Grade = C");
    } else {
        printf("Grade = D");
    }
    */

    if(nilai > 90){
        printf("Grade = A");
    } else {
        if(nilai > 80){
            printf("Grade = B");
        } else {
            if(nilai > 70){
                printf("Grade = C");
            } else {
                printf("Grade = D");
            }
        }

    }
}

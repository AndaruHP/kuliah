#include<stdio.h>
int main(){
    int pH;
    scanf("%d", &pH);

    if(pH > 7){
        if(pH > 12){
            printf("Alkaline");
        } else{
            printf("Very Alkaline");
        }
    } else {
        if(pH == 7){
            printf("Neutral");
        } else {
            if(pH > 2){
                printf("Acidic");
            } else {
                printf("Very Acidic");
            }
        }
    }
}

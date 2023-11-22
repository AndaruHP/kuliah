#include<stdio.h>
int main(){
    int n;
    printf("n = ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            printf("*");
        }
        printf("\n");
    }
}

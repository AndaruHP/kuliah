#include<stdio.h>

int main(){
    int n = 15, a = 15;
    for(int i = 5; i > 0; i--){
        printf("%d ", a);
        a -= i;
    }
    do{
        a += 3;
        printf("%d ", a);
    } while(a < n);
}

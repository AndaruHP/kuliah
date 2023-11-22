#include<stdio.h>
int main(){
    printf("Input = ");
    char n;
    scanf("%c", &n);
    if((n >= 32 && n <= 47) || (n >= 58 && n <= 64) || (n >= 91 && n <= 96) || (n >= 123 && n <= 126)){
        printf("Output: Ini Simbol");
    } else if(n >= 48 && n <= 57){
        printf("Output: Ini Angka");
    } else if((n >= 65 && n <= 90) || (n >= 97 && n <= 122)){
        printf("Output: Ini Huruf");
    }
}


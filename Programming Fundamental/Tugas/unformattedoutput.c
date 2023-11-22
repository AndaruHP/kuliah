#include<stdio.h>

int main(){
    /*
    putchar(87);
    putch('A');
    puts("LOL");
    putchar(87);
    //ASCII of \n is 10
    */
    int day, month, year;
    scanf("%d%*c%d%*c%d", &day, &month, &year);
    printf("%d/%d/%d", day, month, year);
    /*
    fflush(stdin); jika ada problem dalam input variabel

    */
}

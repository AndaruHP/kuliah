#include<stdio.h>

int main(){
    int  date, month, year;
    printf("Date: ");
    scanf("%2d%2d%4d", &date, &month, &year);
    printf("Tanggal: %02d\n", date);
    printf("Bulan: %02d\n", month);
    printf("Tahun: %4d\n", year);
}

#include<stdio.h>

enum months {
    JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

int main(){
    enum months month;

    char *monthname[13] = {" ", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    for(month = JAN; month <= DEC; month++){
        printf("Month %2d\t: %s\n", month, monthname[month]);
    }
    
}
#include<stdio.h>
int main(){
    printf("Masukkan A B C D\n");
    float a, b, c, d;
    scanf("%f %f %f %f", &a, &b, &c, &d);
    printf("%f\n", (a + b + c + d)/4);
    printf("%f\n", a * b * c * d);
    printf("%f\n", a - b + c/d);
    printf("%f", b * c + a - d);
    return 0;
}

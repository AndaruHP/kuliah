// Online C compiler to run C program online
#include <stdio.h>


int max(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}
int min(int a, int b){
    if(a < b){
        return a;
    } else {
        return b;
    }
}


int main() {
    // Write C code here
    int n = 10, kecil = 2e9, besar = -2e9;

    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);

        kecil = min(kecil, temp);
        besar = max(besar, temp);
    }

    printf("%d\n", besar);
    printf("%d\n", kecil);

    return 0;
}

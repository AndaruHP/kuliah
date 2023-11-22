// Online C compiler to run C program online
#include <stdio.h>


int max(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}

int main() {
    // Write C code here
    int n = 10, a[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int ans;
    int b = a[0];

    for(int i = 1; i < n; i++){
        b = max(b, a[i]);
    }

    printf("%d", b);

    return 0;
}

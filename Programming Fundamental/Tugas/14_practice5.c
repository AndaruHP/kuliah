// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    int n = 10, a[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int min = a[0], max = a[0];

    for(int i = 1; i < n; i++){
        if(max >= a[i]){
            max = max;
        } else {
            max = a[i];
        }
        if(min <= a[i]){
            min = min;
        } else {
            min = a[i];
        }
    }
    printf("max = %d\n", max);
    printf("min = %d\n", min);

    return 0;
}

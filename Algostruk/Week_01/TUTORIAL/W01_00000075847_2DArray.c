#include<stdio.h>

void printArray(int arr[][3]){
    int row, col;

    printf("Isi dari array\n");
    for(row = 0; row < 3; row++){
        for(col = 0; col < 3; col++){
            printf("%d ", arr[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int randomNumber[3][3] = {
        {1, 2, 3}, {6, 5, 4}, {7, 8, 9}
    };
    printArray(randomNumber);
}

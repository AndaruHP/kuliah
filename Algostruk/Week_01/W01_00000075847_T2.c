#include<stdio.h>

void addMatrix(int matrix[3][3]){
    for(int i = 0; i < 3; i++){
        scanf("%d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2]); 
    }
}

void perkalian1(int matrix1[3][3], int matrix2[3][3], int hasil[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            hasil[i][j] = 0;
            for(int k = 0; k < 3; k++){
                hasil[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void perkalian2(int matrix1[3][3], int matrix2[3][3], int hasil[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            hasil[i][j] = 0;
            for(int k = 0; k < 3; k++){
                hasil[i][j] += matrix2[i][k] + matrix1[k][j];
            }
        }
    }
}

void penjumlahan(int matrix1[3][3], int matrix2[3][3], int hasil[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            hasil[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void transpose1(int matrix1[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix1[i][j] = matrix1[j][i];
        }
    }
}

void transpose2(int matrix2[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix2[i][j] = matrix2[j][i];
        }
    }
}

void printhasil(int hasil[3][3]){
    for(int i = 0; i < 3; i++){
        printf("%d %d %d\n", hasil[i][0], hasil[i][1], hasil[i][2]);
    }
}

int main(){
    int matrix1[3][3];
    int matrix2[3][3];
    int hasil[3][3];

    printf("Matrix Pertama:\n");
    addMatrix(matrix1);
    printf("Matrix Kedua:\n");
    addMatrix(matrix2);

    printf("1. Perkalian dua buah matrix\n2. Penjumlahan dua buah matrix\n3. Transpose dua buah matrix\n4. Keluar\n Pilihan : ");
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("1. Matrix pertama kali matrix kedua\n2. Matrix kedua kali pertama\nPilihan : ");
        int choice2;
        scanf("%d", &choice2);
        switch (choice2){
        case 1:
            perkalian1(matrix1, matrix2, hasil);
            printf("Hasil perkalian:\n");
            printhasil(hasil);
            break;
        
        case 2:
            perkalian2(matrix1, matrix2, hasil);
            printf("Hasil perkalian:\n");
            printhasil(hasil);
            break;
        }
        break;

    case 2:
        penjumlahan(matrix1, matrix2, hasil);
        printf("Hasil penjumlahan:\n");
        printhasil(hasil);
        break;

    case 3:
        transpose1(matrix1);
        printf("Hasil transpose matrix pertama:\n");
        printhasil(matrix1);
        transpose1(matrix2);
        printf("Hasil transpose matrix kedua:\n");
        printhasil(matrix2);
        break;

    default:
    printf("\nProgram selesai");
        break;
    }


}
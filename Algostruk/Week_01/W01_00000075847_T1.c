#include<stdio.h>

void upper(char *kalimat){
    int i;
    for (i = 0; kalimat[i] != '\0'; i++){
        if (kalimat[i] >= 'a' && kalimat[i] <= 'z')
            kalimat[i] = kalimat[i] - 32;
    }
    printf("Output: %s", kalimat);

}
void lower(char *kalimat){
    int i;
    for (i = 0; kalimat[i] != '\0'; i++){
        if (kalimat[i] >= 'A' && kalimat[i] <= 'Z')
            kalimat[i] = kalimat[i] + 32;
    }
    printf("Output: %s", kalimat);
}
void upow(char *kalimat){
    int i;
    for (i = 0; kalimat[i] != '\0'; i++){
        if (kalimat[i] >= 'A' && kalimat[i] <= 'Z'){
            kalimat[i] = kalimat[i] + 32;
        } else if(kalimat[i] >= 'a' && kalimat[i] <= 'z'){
            kalimat[i] = kalimat[i] - 32;
        }
    }
    printf("Output: %s", kalimat);
}

int main(){
    printf("1. Uppercase\n2. Lowercase\n3. Switching\n4. Keluar\nPilihan: ");
    int ans;
    char kalimat[100];
    scanf("%d", &ans);
    switch(ans){
    case 1:
        printf("Masukkan kalimat: ");
        scanf(" %[^\n]s", kalimat);
        upper(kalimat);
        break;
    case 2:
        printf("Masukkan kalimat: ");
        scanf(" %[^\n]s", kalimat);
        lower(kalimat);
        break;
    case 3:
        printf("Masukkan kalimat: ");
        scanf(" %[^\n]s", kalimat);
        upow(kalimat);
        break;
    case 4:
        printf("Program Closed");
        break;
    }
}

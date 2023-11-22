#include<stdio.h>
#include<stdlib.h>

int banyak = 0;

typedef struct Data {
    char nama[25];
    char domisili[25];
    char hubungan[25];
    char nomor[25];
    char email[25];
    char kampus[25];
    char gender;
    int urutan;
    struct Data *next;
} Data;

void readfile(Data **head, Data **tail){
    FILE *fp = fopen("Andaru75847DaftarTeman.txt", "r");

    if(fp == NULL){
        printf("\nTidak Ada Data Sama Sekali\n");

    }
    while(!feof(fp)){
        banyak++;
        //printf("%d\n", banyak);
        Data *node = (Data*) malloc (sizeof(Data));
        fscanf(fp, "%[^//]//%[^//]//%[^//]//%[^//]//%[^//]//%[^//]//%c\n", node->nama, node->domisili, node->hubungan, node->nomor, node->email, node->kampus, &node->gender);
        node->urutan = banyak;

        node->next = NULL;

        if(*head == NULL){
            *head = *tail = node;
        } else {
            (*tail)->next = node;
            *tail = node;
        }
    }

    fclose(fp);
}

void Tambah(Data **head, Data **tail){
    banyak++;
    Data *node = (Data*) malloc (sizeof(Data));

    if(*head == NULL){
        *head = *tail = node;
    } else {
        (*tail)->next = node;
        node->next = NULL;
        *tail = node;
    }

    printf("Nama\t\t\t: ");
    scanf("%[^\n]", node->nama); fflush(stdin);
    printf("Jenis Kelamin (L/P)\t\t\t: ");
    scanf("%c", &node->gender); fflush(stdin);
    printf("Domisili\t\t\t: ");
    scanf("%[^\n]", node->domisili); fflush(stdin);
    printf("Hubungan\t\t\t: ");
    scanf("%[^\n]", node->hubungan); fflush(stdin);
    printf("Nomor Telepon\t\t\t: ");
    scanf("%[^\n]", node->nomor); fflush(stdin);
    printf("Alamat Email\t\t\t: ");
    scanf("%[^\n]", node->email); fflush(stdin);
    printf("Universitas\t\t\t: ");
    scanf("%[^\n]", node->kampus); fflush(stdin);

    node->urutan = banyak;

    FILE *fp = fopen("Andaru75847DaftarTeman.txt", "a+");
    fprintf(fp, "%s//%s//%s//%s//%s//%s//%c\n", node->nama, node->domisili, node->hubungan, node->nomor, node->email, node->gender);
    fclose(fp);


}

void TampilU(Data **head){
    Data *curr = *head;
    if(*head == NULL){
        printf("\nTidak Ada Data Sama Sekali\n");
    } else {
        while(curr != NULL){
            printf("%s\t\t\t%s\t\t\t%s\n", curr->nama, curr->domisili, curr->nomor);
            curr = curr->next;
        }
    }

}

void TampilD(Data **head){
    Data *curr = *head;
    Data *temp = curr;
    if(*head == NULL){
        printf("\nTidak Ada Data Sama Sekali\n");
    } else {
        printf("%d/%d\n", curr->urutan, banyak);
        printf("Nama: %s\n", curr->nama);
        printf("Domisili: %s\n", curr->domisili);
        printf("Hubungan: %s\n", curr->hubungan);
        printf("Nomor Telepon: %s\n", curr->nomor);
        printf("Email: %s\n", curr->email);
        printf("Kampus: %s\n", curr->kampus);
    }

    int pilihan2;
    printf("Navigasi\n1. Selanjutnya\nPilihan: ");
    scanf("%d", &pilihan2);

    switch(pilihan2){
        case 1:
        temp = temp->next;
            if(temp == NULL) {
                temp = curr;
                TampilD(&curr);
                return;
            }
            TampilD(&temp);
        break;
    }
}

int main(){
    Data *head = NULL;
    Data *tail = NULL;

    int pilihan, pilihan1;

    readfile(&head, &tail);

    do {
        printf("HALAMAN UTAMA\n");
        printf("1. Data Kontak\n2. Tambahkan Kontak\n3. Hapus Kontak\n4. About Me\n5. Keluar\nPilihan: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        switch(pilihan){
            case 1:
                printf("DATA KONTAK\n");
                printf("1. Tampilan Umum\n2. Tampilan Detail\nPilihan: ");
                scanf("%d", &pilihan1);
                fflush(stdin);

                switch(pilihan1){
                    case 1:
                        TampilU(&head);
                    break;
                    case 2:
                        TampilD(&head);
                    break;
                }
            break;
            case 2:
                printf("TAMBAHKAN KOTAK\n");
                Tambah(&head, &tail);
            break;
            case 3:
                printf("HAPUS KONTAK\n");
            break;
            case 4:
                printf("ABOUT ME\n");
            break;
            default:
            break;
        }
    } while(pilihan != 5);
    

}
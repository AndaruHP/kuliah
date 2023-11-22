#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa
{
    char nama[40];
    char jurusan[20];
    int nilai;
} Mahasiswa;

void showData(int total, Mahasiswa mahasiswa[]);
void shellSort(int total, Mahasiswa mahasiswaTemp[]);
int binarySearch(int total, Mahasiswa mahasiswa[], char cari[]);
void search(int total, Mahasiswa mahasiswa[]);

int main()
{
    int total = 0;
    Mahasiswa mahasiswa[20];
    FILE *fp = fopen("database_nilai.txt", "r");
    if (fp == NULL)
    {
        printf("File tidak ditemukan\n");
        return -1;
    }
    while (!feof(fp))
    {
        fscanf(fp, "%[^😭]😭%[^😭]😭%d\n", mahasiswa[total].nama, mahasiswa[total].jurusan, &mahasiswa[total].nilai);
        total++;
    }
    fclose(fp);

    int pilihan;
    do
    {
        printf("Manajemen Nilai Mahasiswa\n1. Tampilkan semua mahasiswa\n2. Cari mahasiswa\n3. Keluar program\nMasukkan pilihan anda: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        switch (pilihan)
        {
        case 1:
            showData(total, mahasiswa);
            break;
        case 2:
            search(total, mahasiswa);
            break;
        case 3:
            printf("Terima kasih telah menggunakan aplikasi ini!\n");
            break;
        default:
            printf("Pilihan tidak tersedia\n");
            break;
        }
    } while (pilihan != 3);
}

void showData(int total, Mahasiswa mahasiswa[])
{
    int mulai = 1;
    printf("--------------------------------------------------------------------------------\n");
    printf("|  No.  |                 Nama                 |        Jurusan        | Nilai |\n");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < total; i++)
    {
        printf("| %5d | %-36s | %-21s | %5d |\n", mulai, mahasiswa[i].nama, mahasiswa[i].jurusan, mahasiswa[i].nilai);
        mulai++;
    }
    printf("--------------------------------------------------------------------------------\n\n");
}

void shellSort(int total, Mahasiswa mahasiswaTemp[])
{
    int gap, i, j;
    Mahasiswa temp;

    for (gap = total / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < total; i++)
        {
            temp = mahasiswaTemp[i];
            for (j = i; j >= gap && strcmp(mahasiswaTemp[j - gap].nama, temp.nama) > 0; j -= gap)
            {
                mahasiswaTemp[j] = mahasiswaTemp[j - gap];
            }
            mahasiswaTemp[j] = temp;
        }
    }
}

void search(int total, Mahasiswa mahasiswa[])
{
    Mahasiswa mahasiswaTemp[20];
    for (int i = 0; i < total; i++)
    {
        mahasiswaTemp[i] = mahasiswa[i];
    }

    char cari[30];
    printf("Masukkan nama mahasiswa yang ingin dicari: ");
    scanf("%[^\n]", cari);
    fflush(stdin);

    shellSort(total, mahasiswaTemp);
    int hasil = binarySearch(total, mahasiswaTemp, cari);

    if (hasil != -1)
    {
        printf("\nMahasiswa ditemukan!\n");
        printf("Nama\t: %s\n", mahasiswaTemp[hasil].nama);
        printf("Jurusan\t: %s\n", mahasiswaTemp[hasil].jurusan);
        printf("Nilai\t: %d\n\n", mahasiswaTemp[hasil].nilai);
    }
    else
    {
        printf("\nMahasiswa tidak ditemukan!\n\n");
    }
}

int binarySearch(int total, Mahasiswa mahasiswa[], char cari[])
{
    int low = 0;
    int high = total - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (strstr(mahasiswa[mid].nama, cari) != NULL)
            // kayak strcmp tapi buat string sebagian
            return mid;
        else if (strcmp(mahasiswa[mid].nama, cari) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

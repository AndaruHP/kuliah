#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[15];
    char nama[30];
    char jurusan[20];
    float tugas;
    float uts;
    float uas;
    float avg;
    char grade[3];
} data;

void searchByNIM(data mahasiswa[], int jumlahData, char nimCari[])
{
    int i;
    int ditemukan = 0;

    for (i = 0; i < jumlahData; i++)
    {
        if (strcmp(mahasiswa[i].nim, nimCari) == 0)
        {
            printf("Data ditemukan:\n");
            printf("Nama    : %s\n", mahasiswa[i].nama);
            printf("NIM     : %s\n", mahasiswa[i].nim);
            printf("Jurusan : %s\n", mahasiswa[i].jurusan);
            printf("Tugas   : %.1f\n", mahasiswa[i].tugas);
            printf("UTS     : %.1f\n", mahasiswa[i].uts);
            printf("UAS     : %.1f\n", mahasiswa[i].uas);
            printf("Mean    : %.2f\n", mahasiswa[i].avg);
            printf("Grade   : %s\n", mahasiswa[i].grade);
            printf("\n");
            ditemukan = 1;
        }
    }

    if (!ditemukan)
    {
        printf("Data tidak ditemukan.\n\n");
    }
}

int main()
{
    FILE *fp1, *fp2;
    fp1 = fopen("dataMahasiswa.txt", "r");
    fp2 = fopen("nilaiMahasiswa.txt", "r");

    if (fp1 == NULL || fp2 == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int awal = 0, j;
    float rata;
    data mahasiswa[100];

    while (!feof(fp1))
    {
        fscanf(fp1, "%[^#]#%[^#]#%[^\n]\n", mahasiswa[awal].nim, mahasiswa[awal].nama, mahasiswa[awal].jurusan);
        fscanf(fp2, "%[^#]#%f#%f#%f#%f#%[^\n]\n", mahasiswa[awal].nim, &mahasiswa[awal].tugas, &mahasiswa[awal].uts, &mahasiswa[awal].uas, &mahasiswa[awal].avg, mahasiswa[awal].grade);
        awal++;
    }

    int max = 100;

    int pilihan;

    do
    {
        printf("Jumlah data(%d/100)\n1. Input Data\n2. Lihat Data\n3. Search by NIM\n4. Keluar\nPilihan: ", awal);
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            if (max != awal && max < awal)
            {
                printf("Masukkan data (NIM#NAMA#JURUSAN#TUGAS#UTS#UAS)\n");
                scanf("%[^#]#%[^#]#%[^#]#%f#%f#%f", mahasiswa[awal].nim, mahasiswa[awal].nama, mahasiswa[awal].jurusan, &mahasiswa[awal].tugas, &mahasiswa[awal].uts, &mahasiswa[awal].uas);
                rata = (mahasiswa[awal].tugas + mahasiswa[awal].uts + mahasiswa[awal].uas) / 3;
                mahasiswa[awal].avg = rata;
                if (rata >= 0 && rata <= 54.99)
                {
                    strcpy(mahasiswa[awal].grade, "E");
                }
                else if (rata >= 55 && rata <= 59.99)
                {
                    strcpy(mahasiswa[awal].grade, "D");
                }
                else if (rata >= 60 && rata <= 64.99)
                {
                    strcpy(mahasiswa[awal].grade, "C-");
                }
                else if (rata >= 65 && rata <= 69.99)
                {
                    strcpy(mahasiswa[awal].grade, "C");
                }
                else if (rata >= 70 && rata <= 74.99)
                {
                    strcpy(mahasiswa[awal].grade, "B-");
                }
                else if (rata >= 75 && rata <= 79.99)
                {
                    strcpy(mahasiswa[awal].grade, "B");
                }
                else if (rata >= 80 && rata <= 84.99)
                {
                    strcpy(mahasiswa[awal].grade, "A-");
                }
                else if (rata >= 85 && rata <= 94.99)
                {
                    strcpy(mahasiswa[awal].grade, "A");
                }
                else if (rata >= 95 && rata <= 100)
                {
                    strcpy(mahasiswa[awal].grade, "A+");
                }

                fp1 = fopen("dataMahasiswa.txt", "a+");
                fp2 = fopen("nilaiMahasiswa.txt", "a+");

                fprintf(fp1, "%s#%s#%s", mahasiswa[awal].nim, mahasiswa[awal].nama, mahasiswa[awal].jurusan);
                fprintf(fp2, "%s#%.1f#%.1f#%.1f#%.2f#%s", mahasiswa[awal].nim, mahasiswa[awal].tugas, mahasiswa[awal].uts, mahasiswa[awal].uas, mahasiswa[awal].avg, mahasiswa[awal].grade);

                fclose(fp1);
                fclose(fp2);
                awal++;
            }
            else
            {
                printf("\nData penuh\n\n");
            }

            break;

        case 2:
            printf("+------+-----------------------------+---------------+------------------+-------+-------+-------+--------+-------+\n");
            printf("|  No  |            Nama             |      NIM      |      Jurusan     | Tugas |  UTS  |  UAS  |  Mean  | Grade |\n");
            printf("+------+-----------------------------+---------------+------------------+-------+-------+-------+--------+-------+\n");

            for (j = 0; j < awal; j++)
            {
                printf("| %03d  | %-27s | %-13s | %-16s | %-5.1f | %-5.1f | %-5.1f | %-6.2f | %-5s |\n", j + 1, mahasiswa[j].nama, mahasiswa[j].nim, mahasiswa[j].jurusan, mahasiswa[j].tugas, mahasiswa[j].uts, mahasiswa[j].uas, mahasiswa[j].avg, mahasiswa[j].grade);
            }
            printf("+------+-----------------------------+---------------+------------------+-------+-------+-------+--------+-------+\n");
            break;

        case 3:
            if (awal == 0)
            {
                printf("Tidak ada data yang tersedia.\n\n");
            }
            else
            {
                char nimCari[15];
                printf("Masukkan NIM yang ingin dicari: ");
                scanf("%s", nimCari);
                searchByNIM(mahasiswa, awal, nimCari);
            }
            break;

        default:
            break;
        }
    } while (pilihan != 4);

    fclose(fp1);
    fclose(fp2);
}
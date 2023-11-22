#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Nama    : Andaru Hymawan Primayudha
    NIM     : 00000075847
    Kelas   : G
    Nilai   :
*/

typedef struct Lagu
{
    char title[50];
    char artist[50];
    char album[50];
    int year;
} Lagu;

void showData(int total, Lagu musik[])
{
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                      DATABASE MUSIK AGUS                                            |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("| Title                                    | Artist              | Album                                       | Year |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < total; i++)
    {
        printf("| %-40s | %-20s | %-42s | %-4d |\n", musik[i].title, musik[i].artist, musik[i].album, musik[i].year);
        // nanti edit ini
    }
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
}

void sortJudul(int total, Lagu musik[])
{
    for (int i = 0; i < total - 1; i++)
    {
        int max = i;

        for (int j = i + 1; j < total; j++)
        {
            if (strcmp(musik[j].title, musik[max].title) < 0)
            {
                max = j;
            }
        }
        Lagu temp = musik[i];
        musik[i] = musik[max];
        musik[max] = temp;
    }
}

void sortTahun(int total, Lagu musik[])
{
    for (int i = 0; i < total - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < total; j++)
        {
            if (musik[j].year < musik[max].year)
            {
                max = j;
            }
        }
        Lagu temp = musik[i];
        musik[i] = musik[max];
        musik[max] = temp;
    }
}

void searchJudul(int total, Lagu musik[])
{
    char cari[50];
    printf("\nMasukkan judul yang ingin dicari: ");
    scanf("%[^\n]", cari);
    fflush(stdin);

    int low = 0;
    int high = total - 1;
    int found = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int comparation = strcmp(musik[mid].title, cari);

        if (comparation == 0)
        {
            found = 1;
            printf("\nData ditemukan!\n");
            printf("Judul\t: %s\n", musik[mid].title);
            printf("Artis\t: %s\n", musik[mid].artist);
            printf("Album\t: %s\n", musik[mid].album);
            printf("Tahun\t: %d\n\n", musik[mid].year);
            break;
        }
        else if (comparation < 0)
        {
            low = mid + 1;
        }
        else if (comparation > 0)
        {
            high = mid - 1;
        }
    }

    if (found == 0)
    {
        printf("Data tidak ditemukan!\n");
    }
}

void searchTahun(int total, Lagu musik[])
{
    Lagu tahun[50];
    int cari;
    int n = 0;
    printf("\nMasukkan tahun yang ingin dicari: ");
    scanf("%d", &cari);
    fflush(stdin);

    for (int i = 0; i < total; i++)
    {
        if (musik[i].year == cari)
        {
            tahun[n] = musik[i];
            n++;
        }
    }

    if (n != 0)
    {
        printf("\nTotal ada %d Lagu\n", n);
        for (int i = 0; i < n; i++)
        {
            printf("%d. %s\n", i + 1, tahun[i].title);
        }
        printf("\n");
    }
    else
    {
        printf("\nTidak ada lagu pada tahun tersebut...\n\n");
    }
}

int main()
{
    Lagu musik[50];
    int total = 0;
    FILE *fp = fopen("database-musik.txt", "r");
    if (fp == NULL)
    {
        printf("File tidak ditemukan!\n");
        exit(1);
    }
    while (!feof(fp))
    {
        fscanf(fp, "%[^*]*%[^*]*%[^*]*%d\n", musik[total].title, musik[total].artist, musik[total].album, &musik[total].year);
        total++;
    }
    fclose(fp);

    int pilihan;
    int pilihan1;
    int pilihan2;

    do
    {
        showData(total, musik);

        printf("\nMenu:\n1. Sort\n2. Search\n3. Exit\n\nPilihan: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        switch (pilihan)
        {
        case 1:
            printf("\nPilih sort berdasarkan:\n1. Judul\n2. Tahun Rilis\n\nPilihan: ");
            scanf("%d", &pilihan1);
            fflush(stdin);
            switch (pilihan1)
            {
            case 1:
                sortJudul(total, musik);
                // menggunakan selection sort
                break;
            case 2:
                sortTahun(total, musik);
                // menggunakan selection sort
                break;
            default:
                printf("\nPilihan tidak tersedia\n");
                break;
            }
            break;
        case 2:
            printf("\nPilih search berdasarkan:\n1. Judul\n2. Tahun Rilis\n\nPilihan: ");
            scanf("%d", &pilihan2);
            fflush(stdin);

            switch (pilihan2)
            {
            case 1:
                sortJudul(total, musik);
                searchJudul(total, musik);
                break;
            case 2:
                searchTahun(total, musik);
                break;
            default:
                printf("\nPilihan tidak tersedia\n");
                break;
            }

            break;
        case 3:
            printf("\nProgram exited...\n");
            break;
        default:
            printf("\nPilihan tidak tersedia\n");
            break;
        }

    } while (pilihan != 3);
}
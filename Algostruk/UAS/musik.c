#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lagu
{
    char title[25];
    char artist[25];
    char album[25];
    int year;
    int value;
} Lagu;

void showData(int total, Lagu musik[])
{
    printf("------------------------------------------------\n");
    printf("|             DATABASE MUSIK BINOMO            |\n");
    printf("------------------------------------------------\n");
    printf("| Title         | Artist    | Album     | Year |\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < total; i++)
    {
        printf("| %-13s | %-9s | %-9s | %-4d |\n", musik[i].title, musik[i].artist, musik[i].album, musik[i].year);
    }
}

void selectionSortJudul(int total, Lagu musik[])
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

void value(int total, Lagu musik[])
{
    for (int i = 0; i < total - 1; i++)
    {
        musik[i].value = i;
    }
}

void selectionSortTahun(int total, Lagu musik[])
{
    for (int i = 0; i < total - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < total; j++)
        {
            if (musik[j].year > musik[max].year)
            {
                max = j;
            }
        }
        Lagu temp = musik[i];
        musik[i] = musik[max];
        musik[max] = temp;
    }
}

void binarySearchJudul(int total, Lagu musik[])
{
    char cari[25];
    printf("Masukkan judul yang ingin dicari: ");
    scanf("%[^\n]", cari);
    fflush(stdin);

    int low = 0;
    int high = total - 1;
    int found = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int compare = strcmp(musik[mid].title, cari);

        if (compare == 0)
        {
            found = 1;
            printf("\nData ditemukan!\n");
            printf("Title\t: %s\n", musik[mid].title);
            printf("Artist\t: %s\n", musik[mid].artist);
            printf("Album\t: %s\n", musik[mid].album);
            printf("Year\t: %d\n", musik[mid].year);
            break;
        }
        else if (compare < 0)
        {
            low = mid + 1;
        }
        else if (compare > 0)
        {
            high = mid - 1;
        }
    }

    if (found == 0)
    {
        printf("Data tidak ditemukan\n");
    }
}

// void binarySearchTahun(int total, Lagu musik[])
// {
//     int low = 0;
//     int high = total - 1;
//     int found = 0;

//     int cari;
//     printf("Masukkan tahun yang ingin dicari: ");
//     scanf("%d", &cari);

//     while (low <= high)
//     {
//         int mid = (low + high) / 2;

//         if (musik[mid].year == cari)
//         {
//             found = 1;
//             printf("\nData ditemukan!\n");
//             printf("Title\t: %s\n", musik[mid].title);
//             printf("Artist\t: %s\n", musik[mid].artist);
//             printf("Album\t: %s\n", musik[mid].album);
//             printf("Year\t: %d\n", musik[mid].year);
//             break;
//         }
//         else if (cari < musik[mid].year)
//         {
//             high = mid - 1;
//         }
//         else if (cari > musik[mid].year)
//         {
//             low = mid + 1;
//         }
//     }
//     if (found == 0)
//     {
//         printf("Data tidak ditemukan\n");
//     }
// }

int main()
{
    Lagu musik[20];
    int total = 0;
    FILE *fp = fopen("database-musik.txt", "r");
    if (fp == NULL)
    {
        printf("File tidak ditemukan\n");
        return -1;
    }

    while (!feof(fp))
    {
        fscanf(fp, "%[^*]*%[^*]*%[^*]*%d\n", musik[total].title, musik[total].artist, musik[total].album, &musik[total].year);
        total++;
    }
    fclose(fp);
    // value(total, musik);

    int pilihan;
    int temp = 1;
    int angkaCari;
    int found;
    int tempAngka;
    do
    {
        showData(total, musik);

        printf("\nMenu:\n1. Sort\n2. Search\n3.Exit\n\nPilihan: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        switch (pilihan)
        {
        case 1:
            printf("\nPilih sort berdasarkan:\n1. Judul\n2. Tahun Rilis\n\nPilihan: ");
            int pilihan1;
            scanf("%d", &pilihan1);
            fflush(stdin);
            switch (pilihan1)
            {
            case 1:
                selectionSortJudul(total, musik);
                value(total, musik);
                temp = 1;
                break;
            case 2:
                selectionSortTahun(total, musik);
                value(total, musik);
                temp = 2;
                break;
            }

            break;
        case 2:
            printf("\nPilih search berdasarkan:\n1. Judul\n2. Tahun Rilis\n\nPilihan: ");
            int pilihan2;
            scanf("%d", &pilihan2);
            fflush(stdin);
            switch (pilihan2)
            {
            case 1:
                binarySearchJudul(total, musik);
                if (temp == 1)
                {
                    selectionSortJudul(total, musik);
                    value(total, musik);
                }
                else if (temp == 2)
                {
                    selectionSortTahun(total, musik);
                    value(total, musik);
                }
                break;
            case 2:
                printf("Masukkan tahun yang ingin dicari: ");
                scanf("%d", &angkaCari);
                found = 0;
                for (int i = 0; i < total - 1; i++)
                {
                    if (musik[i].year == angkaCari)
                    {
                        found = 1;
                        tempAngka = i;
                        break;
                    }
                }

                if (found == 1)
                {
                    printf("\nData ditemukan!\n");
                    printf("Title\t: %s\n", musik[tempAngka].title);
                    printf("Artist\t: %s\n", musik[tempAngka].artist);
                    printf("Album\t: %s\n", musik[tempAngka].album);
                    printf("Year\t: %d\n", musik[tempAngka].year);
                }
                else
                {
                    printf("Data tidak ditemukan\n");
                }
                // selectionSortTahun(total, musik);
                // value(total, musik);
                // binarySearchTahun(total, musik);
                // if (temp == 1)
                // {
                //     selectionSortJudul(total, musik);
                //     value(total, musik);
                // }
                // else if (temp == 2)
                // {
                //     selectionSortTahun(total, musik);
                //     value(total, musik);
                // }
                // break;
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

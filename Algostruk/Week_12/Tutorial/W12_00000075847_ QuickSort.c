#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *bil, int l, int r)
{
    int pivot = bil[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (bil[j] < pivot)
        {
            i++;
            swap(&bil[i], &bil[j]);
        }
    }
    swap(&bil[i + 1], &bil[r]);

    return i + 1;
}

void quickSort(int *bil, int l, int r)
{
    if (l < r)
    {
        int pi = partition(bil, l, r);
        quickSort(bil, l, pi - 1);
        quickSort(bil, pi + 1, r);
    }
}

int main()
{
    int i, n, *bil;
    printf("Banyak bilangan: ", &n);
    scanf("%d", &n);
    bil = (int *)malloc(n * sizeof(int));
    // apa perbedaan malloc ketika di depanya ada (int*) dan tidak ada?
    for (i = 0; i < n; i++)
    {
        printf("Bilangan ke-%d: ", i + 1);
        scanf("%d", &bil[i]);
    }
    quickSort(bil, 0, n - 1);
    printf("Hasil pengurutan: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", bil[i]);
    }
    free(bil);
    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int heapify(int *bil, int n, int i)
{
    int maks = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && bil[l] > bil[maks])
    {
        maks = l;
    }
    if (r < n && bil[r] > bil[maks])
    {
        maks = r;
    }
    if (maks != i)
    {
        swap(&bil[i], &bil[maks]);
        heapify(bil, n, maks);
    }
}

int heapSort(int *bil, int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(bil, n, i);
    }
    for (i = n - 1; i >= 0; i--)
    {
        swap(&bil[0], &bil[i]);
        heapify(bil, i, 0);
    }
}

int main()
{
    int i, n, *bil;
    printf("Banyak bilangan: ");
    scanf("%d", &n);
    bil = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        printf("Bilangan ke-%d: ", i + 1);
        scanf("%d", &bil[i]);
    }
    heapSort(bil, n);
    printf("Hasil pengurutan: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", bil[i]);
    }
    free(bil);
    printf("\n");
    return 0;
}
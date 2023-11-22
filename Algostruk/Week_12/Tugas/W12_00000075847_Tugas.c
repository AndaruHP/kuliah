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

    if (l < n && bil[l] < bil[maks])
    {
        maks = l;
    }
    if (r < n && bil[r] < bil[maks])
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

void mergeSort(int *bil, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(bil, l, m);
        mergeSort(bil, m + 1, r);
        merge(bil, l, m, r);
    }
}

void merge(int *bil, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = bil[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = bil[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        {
            bil[k] = L[i];
            i++;
        }
        else
        {
            bil[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        bil[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        bil[k] = R[j];
        j++;
        k++;
    }
}

int partition(int *bil, int l, int r)
{
    int pivot = bil[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (bil[j] > pivot)
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
        quickSort(bil, pi + 1, r);
        quickSort(bil, l, pi - 1);
    }
}

void shellSort(int *bil, int n)
{
    int i, j, gap;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            int temp = bil[i];
            for (j = i; j >= gap && bil[j - gap] < temp; j -= gap)
            {
                bil[j] = bil[j - gap];
            }
            bil[j] = temp;
        }
    }
}

int input(int **data)
{
    int i, n;
    printf("Banyak bilangan: ");
    scanf("%d", &n);
    *data = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        printf("Input bilangan ke-%d: ", i + 1);
        scanf("%d", &(*data)[i]);
    }

    return n;
}

void output(int *data, int n)
{
    int i;

    printf("Hasil setelah di sort: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    free(data);
}

int main()
{
    int i, n, *data;
    int pilihan;

    do
    {
        printf("1. Reverse Heap Sort\n2. Reverse Merge Sort\n3. Reverse Quick Sort\n4. Reverse Shell Sort\n5. Keluar\nPilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            n = input(&data);
            // bubbleSort(data, n);
            heapSort(data, n);
            output(data, n);
            printf("\n");
            break;
        case 2:
            n = input(&data);
            // selectionSort(data, n);
            mergeSort(data, 0, n - 1);
            output(data, n);
            printf("\n");
            break;
        case 3:
            n = input(&data);
            // insertionSort(data, n);
            quickSort(data, 0, n - 1);
            output(data, n);
            printf("\n");
            break;
        case 4:
            // LinkedList *bucket[10];
            n = input(&data);
            // input1(&n, &data);
            // radixSort(data, n);
            shellSort(data, n);
            output(data, n);
            printf("\n");
            break;
        }
    } while (pilihan != 5);

    return 0;
}
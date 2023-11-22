#include <stdio.h>

int interpolationSearch(int *arr, int size, int key)
{
    int low, pos, high;

    low = 0;
    high = size - 1;

    do
    {
        pos = low + ((key - arr[low]) * (high - low) / (arr[high] - arr[low]));

        if (key == arr[pos])
        {
            return pos;
        }
        else if (key < arr[pos])
        {
            high = pos - 1;
        }
        else if (key > arr[pos])
        {
            low = pos + 1;
        }
    } while (key >= arr[low] && key <= arr[high]);

    return -1;
}

void shellSort(int *bil, int n)
{
    int i, j, gap;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            int temp = bil[i];
            for (j = i; j >= gap && bil[j - gap] > temp; j -= gap)
            {
                bil[j] = bil[j - gap];
            }
            bil[j] = temp;
        }
    }
}

void printArray(int *arr, int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        print("%d ", arr[i]);
    }
    print("\n");
}

int main()
{
    int numbers[] = {2, 4, 3, 123, 23, 56, 7895, 456, 342, 67, 2345};
    int size = sizeof(numbers) / 4;
    int i, search, found = 0;

    printf("Before sorting: ");
    printArray(numbers, size);
    shellSort(numbers, size);
    printf("After sorting: ");
    printArray(numbers, size);

    printf("Enter a number to search: ");
    scanf("%d", &search);

    found = interpolationSearch(numbers, size, search);

    if (found != -1)
    {
        printf("Angka %d ditemukan pada index ke-%d", search, found);
    }
    else
    {
        printf("Angka %d tidak ditemukan", search);
    }
    return 0;
}
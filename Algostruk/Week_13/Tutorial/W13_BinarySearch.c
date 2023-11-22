#include <stdio.h>

int binarySearch(int *arr, int size, int key)
{
    int low, mid, high;

    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else if (key > arr[mid])
        {
            low = mid + 1;
        }
    }

    return -1;
}

void shellShort(int *bil, int n)
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
        printf("%d ", arr[i]);
    }
    print("\n");
}

int main()
{
    int numbers[] = {2, 4, 3, 123, 23, 56, 7895, 456, 342, 67, 2345};
    int size = sizeof(numbers) / 4;
    int i, search, found = 0;

    print("Before sorting: ");
    printArray(numbers, size);
    shellShort(numbers, size);
    print("After sorting: ");
    printArray(numbers, size);

    printf("Enter a number to search: ");
    scanf("%d", &search);

    found = binarySearch(numbers, size, search);

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
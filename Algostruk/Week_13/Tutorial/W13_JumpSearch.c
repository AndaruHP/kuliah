#include <stdio.h>
#include <math.h>

int jumpSearch(int *arr, int size, int key)
{
    int start, jump, i;

    start = 0;
    jump = sqrt(size);
    printf("\nAkar kuadrat terdekat dari %d = %d", size, jump);

    while (key >= arr[jump] && jump < size)
    {
        start = jump;
        jump += sqrt(size);
        if (jump > size - 1)
        {
            jump = size;
        }

        for (i = start; i < jump; i++)
        {
            if (key == arr[i])
            {
                return i;
            }
        }
    }

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
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int numbers[] = {2, 4, 3, 123, 23, 56, 7895, 456, 342, 67, 2345};
    int size = sizeof(numbers) / 4;
    int i, search, found = 0;

    print("Array before sorting: ");
    printArray(numbers, size);
    shellSort(numbers, size);
    print("Array after sorting: ");
    printArray(numbers, size);

    printf("Enter a number to search: ");
    scanf("%d", &search);

    found = jumpSearch(numbers, size, search);

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
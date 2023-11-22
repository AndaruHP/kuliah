#include <stdio.h>

int main()
{
    int numbers[] = {2, 4, 3, 123, 23, 56, 7895, 456, 342, 67, 2345};
    int size = sizeof(numbers) / 4;
    int i, search, found = 0;

    printf("Enter a number to search: ");
    scanf("%d", &search);

    for (i = 0; i < size; i++)
    {
        if (search == numbers[i])
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        printf("Angka %d ditemukan pada index ke-%d", search, i);
    }
    else
    {
        printf("Angka %d tidak ditemukan", search);
    }
    return 0;
}
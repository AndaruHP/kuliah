#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *data, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        temp = i;

        for (j = i + 1; j < n; j++)
        {
            if (data[j] > data[temp]) // cuma diganti di bagian ini
            {
                temp = j;
            }
        }

        if (temp != i)
        {
            swap(&data[temp], &data[i]);
        }
    }
}

void bubbleSort(int *data, int n)
{
    int i, j;

    for (i = 1; i < n; i++)
    {
        for (j = n - 1; j >= 1; j--)
        {
            if (data[j] > data[j - 1]) // Perbedaanya hanya di sini
            {
                swap(&data[j], &data[j - 1]);
            }
        }
    }
}

void insertionSort(int *data, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        temp = data[i];

        for (j = i - 1; j >= 0 && data[j] < temp; j--) // Diganti di bagian ini saja
        {
            data[j + 1] = data[j];
        }

        data[j + 1] = temp;
    }
}

typedef struct LinkedList
{
    int value;
    struct LinkedList *next;
} LinkedList;

void insertionNode(int val, LinkedList **head)
{
    LinkedList *newNode = (LinkedList *)malloc(sizeof(LinkedList));
    newNode->value = val;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        LinkedList *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void radixSort(int *data, int n)
{
    int i, j, maks;

    LinkedList *bucket[10];
    for (i = 0; i < 10; i++)
    {
        bucket[i] = NULL;
    }

    for (i = 0; i < n; i++)
    {
        if (i == 0 || maks < data[i])
        {
            maks = data[i];
        }
    }

    int totalIterasi = 0;
    while (maks > 0)
    {
        maks /= 10;
        totalIterasi++;
    }

    int pembagi = 1;
    for (i = 0; i < totalIterasi; i++)
    {
        for (j = 0; j < n; j++)
        {
            int digit = (data[j] / pembagi) % 10;
            digit = 9 - digit;
            insertionNode(data[j], &bucket[digit]);
        }
        pembagi *= 10;

        int idx = 0;
        for (j = 0; j < 10; j++)
        {
            LinkedList *temp = bucket[j];
            while (temp != NULL)
            {
                data[idx] = temp->value;
                idx++;
                temp = temp->next;
            }
            // kosongkan linked list pada bucket
            LinkedList *current = bucket[j];
            while (current != NULL)
            {
                LinkedList *next = current->next;
                free(current);
                current = next;
            }
            bucket[j] = NULL;
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

void input1(int *n, int **data)
{
    printf("Masukkan jumlah data yang akan di sort: ");
    scanf("%d", n);

    *data = (int *)malloc(sizeof(int) * (*n));
    for (int i = 0; i < *n; i++)
    {
        printf("Input bilangan ke-%d: ", i + 1);
        scanf("%d", (*data + i));
    }
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
        printf("1. Reverse Bubble Sort\n2. Reverse Selection Sort\n3. Reverse Insertion Sort\n4. Reverse Radix Sort\n5. Keluar\nPilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            n = input(&data);
            bubbleSort(data, n);
            output(data, n);
            printf("\n");
            break;
        case 2:
            n = input(&data);
            selectionSort(data, n);
            output(data, n);
            printf("\n");
            break;
        case 3:
            n = input(&data);
            insertionSort(data, n);
            output(data, n);
            printf("\n");
            break;
        case 4:
            // LinkedList *bucket[10];
            input1(&n, &data);
            radixSort(data, n);
            output(data, n);
            printf("\n");
            break;
        }
    } while (pilihan != 5);

    return 0;
}
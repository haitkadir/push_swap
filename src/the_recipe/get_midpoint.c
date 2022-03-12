#include "../push_swap.h"

static void swap(int* a, int* b)

{
    int t = *a;
    *a = *b;
    *b = t;
}

static int partition (int arr[], int low, int high)

{

    int pivot;
    int i;
    int j;

    pivot = arr[high];
    i = (low - 1);
    for (j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
} 

static void quickSort(int arr[], int low, int high)

{

    if (low < high)

    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }

}

int get_midpoint(int *arr, int size)

{

    int i;
    int newarr[size];

    ft_memcpy(newarr, arr, size * sizeof(int));

    quickSort(newarr, 0, size - 1);
    i = (size / 2);

    return (newarr[i]);

}
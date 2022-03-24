#include "../push_swap.h"

static void swap(int *a, int *b)

{
	int t = *a;
	*a = *b;
	*b = t;
}

static int partition(int arr[], int low, int high)

{
	int pivot;
	int i;
	int j;

	pivot = arr[high];
	i = (low - 1);
	j = low;
	while (j < high)
	{
		if (arr[j] >= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
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

int get_midpoint_b(t_stack *stack, int chanck_len)
{
	int	i;
	int	newarr[stack->b_len];

	i = 0;
	ft_memcpy(newarr, stack->b, stack->b_len * sizeof(int));
	quickSort(newarr, 0, stack->b_len - 1);
	i = (chanck_len / 2);
	return (newarr[i]);
}

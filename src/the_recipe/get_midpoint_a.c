#include "../push_swap.h"

// static void swap(int *a, int *b)

// {
// 	int t = *a;
// 	*a = *b;
// 	*b = t;
// }

// static int partition(int arr[], int low, int high)

// {
// 	int pivot;
// 	int i;
// 	int j;

// 	pivot = arr[high];
// 	i = (low - 1);
// 	j = low;
// 	while (j < high)
// 	{
// 		if (arr[j] <= pivot)
// 		{
// 			i++;
// 			swap(&arr[i], &arr[j]);
// 		}
// 		j++;
// 	}
// 	swap(&arr[i + 1], &arr[high]);
// 	return (i + 1);
// }

// static void quickSort(int arr[], int low, int high)

// {
// 	if (low < high)
// 	{
// 		int pi = partition(arr, low, high);
// 		quickSort(arr, low, pi - 1);
// 		quickSort(arr, pi + 1, high);
// 	}
// }

static void sort_arr(int *arr, int length)
{
    int temp;

    for (int i = 0; i < length; i++) {
        for (int j = i+1; j < length; j++) {     
           if(arr[i] > arr[j]) {    
               temp = arr[i];    
               arr[i] = arr[j];    
               arr[j] = temp;    
           }     
        }     
    }  
    
}

int get_midpoint_a(t_stack *stack, int chanck_len, int fixed_len)
{
	int	i;
	int	*newarr;
	int res;

	i = 0;
	newarr = 0;
	newarr = (int *)ft_calloc(stack->a_len + 1, sizeof(int));
	if (!newarr)
		return (0);
	ft_memcpy(newarr, stack->a, stack->a_len * sizeof(int));
	sort_arr(newarr, stack->a_len);
	i = (chanck_len / 2);
	res = newarr[i];
	free(newarr);
	if (chanck_len == fixed_len)
	{
		stack->a_chunck_min = newarr[0];
		stack->a_chunck_max = newarr[chanck_len - 1];
	}
	return (res);
}
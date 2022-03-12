#include "../push_swap.h"

void	quicksort(t_stack *stack, int low, int high)
{
	int i;
	int pi;

	i = 0;
	if (low < high)
	{
		stack->pivot_a = get_midpoint(stack->a, stack->a_len);
		while (i < stack->a_len)
		{
			if (stack->a[i] < stack->pivot_a)
			{
				int pi = partition(stack->a, low, high); 
				quickSort(stack, low, pi - 1);
				quickSort(stack, pi + 1, high);
			}
		}
	}
}

#include "../push_swap.h"

int	sorted(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	quicksort(t_stack *stack)
{
	push_b(stack, stack->a_len);
	// push_a(stack, stack->b_len);
}

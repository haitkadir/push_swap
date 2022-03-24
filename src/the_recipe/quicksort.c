#include "../push_swap.h"

int is_sorted_a(t_stack *stack, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int is_sorted_b(t_stack *stack, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (stack->b[i] < stack->b[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void quicksort(t_stack *stack)
{
	push_b(stack, stack->a_len);
}

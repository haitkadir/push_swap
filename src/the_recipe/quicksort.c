#include "../push_swap.h"

int is_sorted_a(t_stack *stack, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}

	return (1);
}

void quicksort(t_stack *stack)
{
	push_b(stack, stack->a_len, stack->a_len);
}


// int is_sorted_a(t_stack *stack, int len)
// {
// 	int i;

// 	i = 0;
// 	while ((len) && (stack->a[i] >= stack->a_chunck_min) && (stack->a[i] <= stack->a_chunck_max))
// 	{
// 		if (stack->a[i] > stack->a[i + 1])
// 			return (0);
// 		len--;
// 		i++;
// 	}
// 	if (len)
// 	{
// 		if (stack->a[0] < stack->a[stack->a_len - 1])
// 			return (0);
// 		i = stack->a_len - 1;
// 		while ((len) && (stack->a[i] >= stack->a_chunck_min) && (stack->a[i] <= stack->a_chunck_max))
// 		{
// 			if (stack->a[i] < stack->a[i - 1])
// 				return (0);
// 			i--;
// 			len--;
// 		}
// 	}
// 	return (1);
// }
#include "../push_swap.h"

// int is_sorted_a(t_stack *stack, int len)
// {
// 	int min_index;
// 	int max_index;

// 	min_index = stack->a_len - 1;
// 	while ((min_index + 1) % stack->a_len)
// 		min_index++;
// 	max_index = min_index;
// 	while (max_index % stack->a_len >= stack->a_chunck_min && max_index % stack->a_len <= stack->a_chunck_max)
// 		max_index--;
// }


// int is_sorted_b(t_stack *stack, int len)
// {
// 	int i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		if (stack->a[i] < stack->a[i + 1])
// 			return (0);
// 		i++;
// 	}

// 	return (1);
// }

static char is_one_chunck(t_stack *stack, char flag)
{
	int i;

	i = 0;
	if (flag == 'a')
	{
		while (i < stack->a_len)
		{
			if (stack->a[i] < stack->a_chunck_min || stack->a[i] > stack->a_chunck_max)
				return (0);
			i++;
		}
	}
	else
	{
		while (i < stack->b_len)
		{
			if (stack->b[i] < stack->b_chunck_min || stack->b[i] > stack->b_chunck_max)
				return (0);
			i++;
		}
	}
	return (1);
}

int is_sorted_a(t_stack *stack, int len, int fixed_len)
{
	int i;
	char flag;
	int j = 0;

	flag = is_one_chunck(stack, 'a');

	i = stack->a_len;
	while (i > 0 && (stack->a[i - 1] >= stack->a_chunck_min) && (stack->a[i - 1] <= stack->a_chunck_max))
	{
		i--;
	}
	if (i >= 0)
	{
		while (--len)
		{
			if (stack->a[i % stack->a_len] > stack->a[(i + 1) % stack->a_len])
			{
				return (0);
			}
			i++;
		}
		while (stack->a[stack->a_len - 1] <= stack->a_chunck_max && stack->a[stack->a_len - 1] >= stack->a_chunck_min && !flag && stack->a_len > 3)
			rra(stack, 1);
	}
	return (1);
}

// int is_sorted_b(t_stack *stack, int len, int fixed_len)
// {
// 	int i;
// 	int j;
// 	int n;

// 	j = len;
// 	n = len;
// 	i = stack->b_len;
// 	while (i > 0 && (stack->b[i - 1] >= stack->b_chunck_min) && (stack->b[i - 1] <= stack->b_chunck_max))
// 	{
// 		i--;
// 	}
// 	if (i >= 0)
// 	{
// 		while (len)
// 		{
// 			if (stack->b[i % stack->b_len] < stack->b[(i + 1) % stack->b_len])
// 			{
// 				return (0);
// 			}
// 			i++;
// 			len--;
// 		}
// 		while (stack->b[stack->b_len - 1] <= stack->b_chunck_max && stack->b[stack->b_len - 1] >= stack->b_chunck_min && !is_one_chunck(stack, 'b') && stack->b_len > 3)
// 			rrb(stack, 1);
// 		// ft_printf("%d %d\n", stack->b_chunck_min, stack->b_chunck_max);
// 		i = 0;
// 		// printf("%d\n", j);
// 		// exit(0);
// 		while (j)
// 		{
// 			i++;
// 			pa(stack, 1);
// 			j--;
// 		}
// 		// push_b(stack, i, i);
// 	}
// 	return (1);
// }




void quicksort(t_stack *stack)
{
	push_b(stack, stack->a_len, stack->a_len);
}

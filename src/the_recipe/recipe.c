#include "../push_swap.h"

static	void	fill_stack(t_stack *stack, char **args)
{
	int	i;

	i = 0;
	while (i < stack->a_len)
	{
		stack->a[i] = ft_atoi(args[i]);
		i++;
	}
}

int	recipe(char **args)
{
	t_stack	*stack;



	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack->a = (int *)ft_calloc(arr_len(args), sizeof(int));
	stack->b = (int *)ft_calloc(arr_len(args), sizeof(int));
	stack->a_len = arr_len(args);
	stack->b_len = 0;
	fill_stack(stack, args);
	quicksort(stack);

	// ft_printf("\n\nstack: A\n\n");
	// int i = 0;
	// while (i < arr_len(args))
	// 	ft_printf(" %d \n", stack->a[i++]);

	// ft_printf("\n\nstack: B\n\n");
	// i = 0;
	// while (i < arr_len(args))
	// 	ft_printf(" %d \n", stack->b[i++]);

	// i = 0;
	// while (i < (stack->a_len - 1))
	// {
	// 	if (stack->a[i] > stack->a[i + 1])
	// 		ft_printf("\n\n not_sorted \n\n");
	// 	i++;
	// }

	return (0);
}
 
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
	fill_stack(stack, args);
	quicksort(stack);
// ft_printf("\n\nstack: A\n\n");
// 	int i = 0;
// 	while (i < stack->a_len)
// 		ft_printf(" %d ", stack->a[i++]);
	return (0);
}

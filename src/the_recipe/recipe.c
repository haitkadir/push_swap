#include "../push_swap.h"

static	void	fill_stack(t_stack *stack, char **args)
{
	int	i;
	int	j;

	i = 0;
	j = stack->len - 1;
	while (i < stack->len)
	{
		stack->a[i] = ft_atoi(args[j]);
		j--;
		i++;
	}
}

int	recipe(char **args)
{
	t_stack	*stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack->a = (int *)ft_calloc(arr_len(args), sizeof(int));
	stack->b = (int *)ft_calloc(arr_len(args), sizeof(int));
	stack->len = arr_len(args);
	fill_stack(stack, args);
	int i = 0;
	while (i < stack->len)
		ft_printf("a: ==> %d:\n", stack->a[i++]);
	return (0);
}

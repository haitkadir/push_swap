#include "../push_swap.h"

static	void	fill_stack(t_stack *stack, char **args)
{
	int	i;
	int	j;

	i = 0;
	j = stack->a_len - 1;
	while (i < stack->a_len)
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
	stack->a_len = arr_len(args);
	fill_stack(stack, args);
ft_printf("\n\nstack: A\n\n");
	int i = 0;
	int j = 0;
	while (i < stack->a_len)
		ft_printf("a: index %d ==> value %d:\n", j++, stack->a[i++]);
	pb(stack);
	pb(stack);
	pb(stack);
	pb(stack);

	// rra(stack);

ft_printf("\n\nstack: B\n\n");
	i = 0;
	j = 0;
	while (i < stack->b_len)
		ft_printf("b: index %d ==> value %d:\n", j++, stack->b[i++]);

	rrr(stack);

ft_printf("\n\nstack: A\n\n");
	i = 0;
	j = 0;
	while (i < stack->a_len)
		ft_printf("a: index %d ==> value %d:\n", j++, stack->a[i++]);

ft_printf("\n\nstack: B\n\n");
	i = 0;
	j = 0;
	while (i < stack->b_len)
		ft_printf("b: index %d ==> value %d:\n", j++, stack->b[i++]);
	return (0);
}

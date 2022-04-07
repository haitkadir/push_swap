#include "../push_swap.h"

static	void	fill_stack(t_stack *stack, char **args)
{
	int	i;

	i = 0;
	while (i < stack->a_len)
	{
		stack->a[i] = ft_atoi(args[i]);
		free(args[i]);
		i++;
	}
	free(args);
}

static void print_a(t_stack *stack)
{
	int	i;

	i = 0;
	ft_printf("\n\n==== Stack A ====\n\n");
	while (i < stack->a_len)
	{
		ft_printf("%d\n", stack->a[i]);
		i++;
	}
}
static void print_b(t_stack *stack)
{
	int	i;

	i = 0;
	ft_printf("\n\n==== Stack B ====\n\n");
	while (i < stack->b_len)
	{
		ft_printf("%d\n", stack->b[i]);
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
		// print_a(stack);
	// int i = 0;
	// while (i < 100)
	// {
	// 	pb(stack, 0);
	// 	i++;
	// }
	// print_b(stack);
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack)
		free(stack);
	exit (0);
}
#include "../push_swap.h"

int	shift_a(t_stack *stack)
{
	int	i;
	int	tmp;

	if (!stack->a_len)
		return (0);
	i = 0;
	tmp = stack->a[i];
	while (i < stack->a_len)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	return (tmp);
}

int	rshift_a(t_stack *stack)
{
	int	i;
	int	tmp;

	if (!stack->a_len)
		return (0);
	i = stack->a_len;
	tmp = stack->a[i - 1];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	return (tmp);
}

int	shift_b(t_stack *stack)
{
	int	i;
	int	tmp;

	if (!stack->b_len)
		return (0);
	i = 0;
	tmp = stack->b[i];
	while (i < stack->b_len)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	return (tmp);
}

int	rshift_b(t_stack *stack)
{
	int	i;
	int	tmp;

	if (!stack->b_len)
		return (0);
	i = stack->b_len;
	tmp = stack->b[i - 1];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	return (tmp);
}

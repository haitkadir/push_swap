#include "../push_swap.h"

static	void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	sa(t_stack *stack)
{
	swap(stack->a[0], stack->a[1]);
}

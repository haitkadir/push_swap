#include "../push_swap.h"

static	void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_stack *stack)
{
	if (stack->a_len < 2)
		return ;
	swap(&stack->a[0], &stack->a[1]);
}

void	sb(t_stack *stack)
{
	if (stack->b_len < 2)
		return ;
	swap(&stack->b[0], &stack->b[1]);
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}

void	pb(t_stack *stack)
{
	int	tmp;

	if (!stack->a_len)
		return ;
	tmp = shift_a(stack);
	rshift_b(stack);
	stack->b[0] = tmp;
	stack->a_len--;
	stack->b_len++;
}

void	pa(t_stack *stack)
{
	int	tmp;

	if (!stack->b_len)
		return ;
	tmp = shift_b(stack);
	rshift_a(stack);
	stack->a[0] = tmp;
	stack->b_len--;
	stack->a_len++;
}

void	ra(t_stack *stack)
{
	int	tmp;

	if (stack->a_len < 2)
		return ;
	tmp = shift_a(stack);
	stack->a[stack->a_len - 1] = tmp;
}

void	rb(t_stack *stack)
{
	int	tmp;

	if (stack->b_len < 2)
		return ;
	tmp = shift_b(stack);
	stack->b[stack->b_len - 1] = tmp;
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}

void	rra(t_stack *stack)
{
	int	tmp;

	if (stack->a_len < 2)
		return ;
	tmp = rshift_a(stack);
	stack->a[0] = tmp;
}

void	rrb(t_stack *stack)
{
	int	tmp;

	if (stack->b_len < 2)
		return ;
	tmp = rshift_b(stack);
	stack->b[0] = tmp;
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}

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
	if (stack->a_len == 0)
		return ;
	swap(&stack->a[0], &stack->a[1]);
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	if (stack->b_len == 0)
		return ;
	swap(&stack->b[0], &stack->b[1]);
	ft_printf("sb\n");
}

void	ss(t_stack *stack)
{
	if (stack->a_len < 2 || stack->b_len < 2)
		return ;
	swap(&stack->a[0], &stack->a[1]);
	swap(&stack->b[0], &stack->b[1]);
	ft_printf("ss\n");
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
	ft_printf("pb\n");
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
	ft_printf("pa\n");
}

void	ra(t_stack *stack)
{
	int	tmp;

	if (stack->a_len == 0)
		return ;
	tmp = shift_a(stack);
	stack->a[stack->a_len - 1] = tmp;
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	int	tmp;

	if (stack->b_len == 0)
		return ;
	tmp = shift_b(stack);
	stack->b[stack->b_len - 1] = tmp;
	ft_printf("rb\n");
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	ft_printf("rr\n");
}

void	rra(t_stack *stack)
{
	int	tmp;

	if (stack->a_len == 0)
		return ;
	tmp = rshift_a(stack);
	stack->a[0] = tmp;
	ft_printf("rra\n");
}

void	rrb(t_stack *stack)
{
	int	tmp;

	if (stack->b_len == 0)
		return ;
	tmp = rshift_b(stack);
	stack->b[0] = tmp;
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	ft_printf("rrr\n");
}

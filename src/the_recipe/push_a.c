#include "../push_swap.h"

static	void	sort_tow(t_stack *stack)
{
	if (stack->b[stack->b_len - 1] >= stack->pivot_b && stack->b_len > 3)
		rrb(stack);
	if (stack->b[stack->b_len - 1] >= stack->pivot_b && stack->b_len > 3)
		rrb(stack);
	if (stack->b[0] < stack->b[1])
		sb(stack);
	pa(stack);
	pa(stack);
}

static	void	push_a_util(t_stack *stack, int *len, int len_to_pa)
{
	int	moves;

	moves = 0;
	while (len_to_pa)
	{
		moves = best_move_b(stack);
		while (moves > 0)
		{
			rb(stack);
			moves--;
		}
		while (moves < 0)
		{
			rrb(stack);
			moves++;
		}
		if (stack->b[0] >= stack->pivot_b)
			pa(stack);
		else
			ft_printf("------------Error-B---------\n");
		*len -= 1;
		len_to_pa--;
	}
}

void	push_a(t_stack *stack, int len, int fixed_len)
{
	int	len_to_push;

	stack->pivot_b = get_midpoint_b(stack, len, fixed_len);
	len_to_push = n_to_pa(stack, stack->b_len);
	if (len == 2)
	{
		sort_tow(stack);
		return ;
	}
	else if (len == 1)
	{
	if (stack->b[stack->b_len - 1] >= stack->pivot_b && stack->b_len > 3)
			rrb(stack);
		pa(stack);
		return ;
	}
	push_a_util(stack, &len, len_to_push);
	push_b(stack, len_to_push, len_to_push);
	push_a(stack, len, fixed_len);
}

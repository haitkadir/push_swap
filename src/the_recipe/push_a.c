#include "../push_swap.h"

static	void	sort_tow(t_stack *stack)
{
	if (stack->b[stack->b_len - 1] >= stack->pivot_b)
		rrb(stack);
	if (stack->b[stack->b_len - 1] >= stack->pivot_b)
		rrb(stack);
	if (stack->b[0] < stack->b[1])
		sb(stack);
	pa(stack);
	pa(stack);
}

static	void	first_move(t_stack *stack, int *len, int len_to_pa)
{
	int	moves;

	moves = 0;
	while (len_to_pa)
	{
		moves = best_move_b(stack);
		while (moves > 0)
		{
			rb(stack);
			stack->track_b++;
			moves--;
		}
		while (moves < 0)
		{
			rrb(stack);
			stack->track_a--;
			moves++;
		}
		pa(stack);
		*len -= 1;
		len_to_pa--;
	}
}

static	void	push_a_util(t_stack *stack, int *len, int len_to_pa)
{
	first_move(stack, len, len_to_pa);
}

void	push_a(t_stack *stack, int len)
{
	int	len_to_push;

	stack->pivot_b = get_midpoint_b(stack, len);
	len_to_push = n_to_pa(stack, stack->b_len);
	if (len == 2)
	{
		sort_tow(stack);
		return ;
	}
	else if (len == 1)
	{
	if (stack->b[stack->b_len - 1] >= stack->pivot_b)
			rrb(stack);
		pa(stack);
		return ;
	}
	push_a_util(stack, &len, len_to_push);
	push_b(stack, len_to_push);
	push_a(stack, len);
}

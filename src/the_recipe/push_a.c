#include "../push_swap.h"

static	void	sort_tow(t_stack *stack)
{
	if (stack->b[0] < stack->b[1])
		sb(stack);
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
			moves--;
		}
		while (moves < 0)
		{
			rrb(stack);
			moves++;
		}
		// if (stack->b[0] >= stack->pivot_b)
			pa(stack);
		// else
		// 	continue;
		*len -= 1;
		len_to_pa--;
	}
}

static void	socend_move(t_stack *stack, int *len, int len_to_pa)
{
	int	i;

	while (len_to_pa)
	{
		i = 0;
		while (stack->b[0] < stack->pivot_b)
		{
			rb(stack);
			i++;
			stack->track_b++;
		}
		pa(stack);
		*len -= 1;
		len_to_pa--;
	}
	while (stack->track_b)
	{
		rrb(stack);
		stack->track_b--;
	}
}

static	void	push_a_util(t_stack *stack, int *len, int len_to_pa)
{
	if (*len == stack->b_len)
		first_move(stack, len, len_to_pa);
	else
		socend_move(stack, len, len_to_pa);
}

void	push_a(t_stack *stack, int len)
{
	int	len_to_push;

	stack->pivot_b = get_midpoint(stack->b, len);
	len_to_push = n_to_pa(stack, len);
	if (len == 2)
	{
		sort_tow(stack);
		pa(stack);
		pa(stack);
		return ;
	}
	else if (len == 1)
	{
		pa(stack);
		return ;
	}
	push_a_util(stack, &len, len_to_push);
	push_b(stack, len_to_push);
	push_a(stack, len);
}

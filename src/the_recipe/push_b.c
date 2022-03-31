#include "../push_swap.h"

static	void	sort_tow(t_stack *stack)
{
	if (stack->a[stack->a_len - 1] <= stack->pivot_a  && stack->a_len > 3)
		rra(stack);
	if (stack->a[stack->a_len - 1] <= stack->pivot_a  && stack->a_len > 3)
		rra(stack);
	if (stack->a[0] > stack->a[1])
		sa(stack);
}

static	void	push_b_util(t_stack *stack, int *len, int len_to_pb)
{
	int	moves;

	moves = 0;
	while (len_to_pb)
	{
		moves = best_move_a(stack);
		while (moves > 0)
		{
			ra(stack);
			moves--;
		}
		while (moves < 0)
		{
			rra(stack);
			moves++;
		}
		if (stack->a[0] < stack->pivot_a)
			pb(stack);
		else
			ft_printf("------------Error-A---------\n");
		*len -= 1;
		len_to_pb--;
	}
}

void	push_b(t_stack *stack, int len, int fixed_len)
{
	int	len_to_push;

	stack->pivot_a = get_midpoint_a(stack, len, fixed_len);
	len_to_push = n_to_pb(stack, stack->a_len);
	if (len == 2)
	{
		sort_tow(stack);
		return ;
	}
	else if (len == 1)
	{
	if (stack->a[stack->a_len - 1] <= stack->pivot_a && stack->a_len > 3)
		rra(stack);
		return ;
	}
	// else if (is_sorted_a(stack, len))
	// 	return ;
	push_b_util(stack, &len, len_to_push);
	push_b(stack, len, fixed_len);
	push_a(stack, len_to_push, len_to_push);
}

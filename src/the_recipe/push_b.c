#include "../push_swap.h"

static	void	sort_tow(t_stack *stack)
{
	if (stack->a[0] > stack->a[1])
		sa(stack);
}

static	void	first_move(t_stack *stack, int *len, int len_to_pb)
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
		// ft_printf("------------num:%d\n", stack->a[0]);
		// if (stack->a[0] < stack->pivot_a)
			pb(stack);
		// else
		// 	continue;
		*len -= 1;
		len_to_pb--;
	}
}

static void	socend_move(t_stack *stack, int *len, int len_to_pb)
{
	int	i;

	while (len_to_pb)
	{
		i = 0;
		while (stack->a[0] >= stack->pivot_a)
		{
			ra(stack);
			i++;
			stack->track_a++;
		}
		pb(stack);
		*len -= 1;
		len_to_pb--;
	}
	while (stack->track_a)
	{
		rra(stack);
		stack->track_a--;
	}
}

static	void	push_b_util(t_stack *stack, int *len, int len_to_pb)
{
	if (*len == stack->a_len)
		first_move(stack, len, len_to_pb);
	else
		socend_move(stack, len, len_to_pb);
}

void	push_b(t_stack *stack, int len)
{
	int	len_to_push;

	stack->pivot_a = get_midpoint(stack->a, len);
	// ft_printf("------------------pivot:%d-----------------\n", stack->pivot_a);
	len_to_push = n_to_pb(stack, len);
	if (len == 2)
	{
		sort_tow(stack);
		return ;
	}
	else if (len == 1)
		return ;
	push_b_util(stack, &len, len_to_push);
	push_b(stack, len);
	push_a(stack, len_to_push);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:45:56 by haitkadi          #+#    #+#             */
/*   Updated: 2022/04/04 19:45:58 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	sort_tow(t_stack *stack)
{
	if (stack->a[stack->a_len - 1] <= stack->pivot_a && stack->a_len > 3)
		rra(stack, 1);
	if (stack->a[stack->a_len - 1] <= stack->pivot_a && stack->a_len > 3)
		rra(stack, 1);
	if (stack->a[0] > stack->a[1])
		sa(stack, 1);
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
			ra(stack, 1);
			moves--;
		}
		while (moves < 0)
		{
			rra(stack, 1);
			moves++;
		}
		if (stack->a[0] < stack->pivot_a)
			pb(stack, 1);
		*len -= 1;
		len_to_pb--;
	}
}

void	push_b(t_stack *stack, int len, int fixed_len)
{
	int	len_to_push;

	stack->pivot_a = get_midpoint_a(stack, len, fixed_len);
	len_to_push = n_to_pb(stack, stack->a_len);
	if (is_sorted_a(stack, len, fixed_len))
		return ;
	if (len == 2)
	{
		sort_tow(stack);
		return ;
	}
	else if (len == 1)
	{
		if (stack->a[stack->a_len - 1] <= stack->pivot_a && stack->a_len > 3)
			rra(stack, 1);
		return ;
	}
	push_b_util(stack, &len, len_to_push);
	push_b(stack, len, fixed_len);
	push_a(stack, len_to_push, len_to_push);
}

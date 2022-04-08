/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 04:45:36 by haitkadi          #+#    #+#             */
/*   Updated: 2022/04/08 04:45:39 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	sort_three(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2])
		ra(stack, 1);
	if (stack->a[1] > stack->a[0] && stack->a[1] > stack->a[2])
		rra(stack, 1);
	if (stack->a[0] > stack->a[1])
		sa(stack, 1);
}

void	quicksort(t_stack *stack)
{
	if (stack->a_len == 3 && !is_sorted_a(stack, stack->a_len))
		sort_three(stack);
	else
		push_b(stack, stack->a_len, stack->a_len);
}

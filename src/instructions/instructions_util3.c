/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_util3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:42:20 by haitkadi          #+#    #+#             */
/*   Updated: 2022/04/05 00:42:23 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_stack *stack, char flag)
{
	if (stack->a_len < 2 || stack->b_len < 2)
		return ;
	sa(stack, 0);
	sb(stack, 0);
	if (flag)
		ft_printf("ss\n");
}

void	rr(t_stack *stack, char flag)
{
	if (stack->a_len < 2 || stack->b_len < 2)
		return ;
	ra(stack, 0);
	rb(stack, 0);
	if (flag)
		ft_printf("rr\n");
}

void	rrr(t_stack *stack, char flag)
{
	if (stack->a_len < 2 || stack->b_len < 2)
		return ;
	rra(stack, 0);
	rrb(stack, 0);
	if (flag)
		ft_printf("rrr\n");
}

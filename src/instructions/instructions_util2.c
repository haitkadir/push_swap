/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_util2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:21:41 by haitkadi          #+#    #+#             */
/*   Updated: 2022/04/04 18:21:45 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack, char flag)
{
	int	tmp;

	if (stack->a_len < 2)
		return ;
	tmp = shift_a(stack);
	stack->a[stack->a_len - 1] = tmp;
	if (flag)
		ft_printf("ra\n");
}

void	rb(t_stack *stack, char flag)
{
	int	tmp;

	if (stack->b_len < 2)
		return ;
	tmp = shift_b(stack);
	stack->b[stack->b_len - 1] = tmp;
	if (flag)
		ft_printf("rb\n");
}

void	rra(t_stack *stack, char flag)
{
	int	tmp;

	if (stack->a_len < 2)
		return ;
	tmp = rshift_a(stack);
	stack->a[0] = tmp;
	if (flag)
		ft_printf("rra\n");
}

void	rrb(t_stack *stack, char flag)
{
	int	tmp;

	if (stack->b_len < 2)
		return ;
	tmp = rshift_b(stack);
	stack->b[0] = tmp;
	if (flag)
		ft_printf("rrb\n");
}

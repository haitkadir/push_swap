/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:21:07 by haitkadi          #+#    #+#             */
/*   Updated: 2022/04/04 18:21:11 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack, char flag)
{
	if (stack->a_len < 2)
		return ;
	swap(&stack->a[0], &stack->a[1]);
	if (flag)
		ft_printf("sa\n");
}

void	sb(t_stack *stack, char flag)
{
	if (stack->b_len < 2)
		return ;
	swap(&stack->b[0], &stack->b[1]);
	if (flag)
		ft_printf("sb\n");
}

void	pb(t_stack *stack, char flag)
{
	int	tmp;

	if (!stack->a_len)
		return ;
	tmp = shift_a(stack);
	stack->a_len--;
	stack->b_len++;
	rshift_b(stack);
	stack->b[0] = tmp;
	if (flag)
		ft_printf("pb\n");
}

void	pa(t_stack *stack, char flag)
{
	int	tmp;

	if (!stack->b_len)
		return ;
	tmp = shift_b(stack);
	stack->b_len--;
	stack->a_len++;
	rshift_a(stack);
	stack->a[0] = tmp;
	if (flag)
		ft_printf("pa\n");
}

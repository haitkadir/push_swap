/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_util1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:21:22 by haitkadi          #+#    #+#             */
/*   Updated: 2022/04/04 18:21:26 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	shift_a(t_stack *stack)
{
	int	i;
	int	tmp;

	if (!stack->a_len)
		return (0);
	i = 0;
	tmp = stack->a[i];
	while (i < stack->a_len - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	return (tmp);
}

int	rshift_a(t_stack *stack)
{
	int	i;
	int	tmp;

	if (!stack->a_len)
		return (0);
	i = stack->a_len - 1;
	tmp = stack->a[i];
	while (i > 1)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	return (tmp);
}

int	shift_b(t_stack *stack)
{
	int	i;
	int	tmp;

	if (!stack->b_len)
		return (0);
	i = 0;
	tmp = stack->b[i];
	while (i < stack->b_len - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	return (tmp);
}

int	rshift_b(t_stack *stack)
{
	int	i;
	int	tmp;

	if (!stack->b_len)
		return (0);
	i = stack->b_len - 1;
	tmp = stack->b[i];
	while (i > 1)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	return (tmp);
}

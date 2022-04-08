/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 05:30:52 by haitkadi          #+#    #+#             */
/*   Updated: 2022/04/08 05:30:54 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"
#include "./gnl/get_next_line.h"
#include <string.h>

static	char	check_apllay(t_stack *stack, char *instruction)
{
	if (!strncmp(instruction, "pa", 3))
		pa(stack, 0);
	else if (!strncmp(instruction, "pb", 3))
		pb(stack, 0);
	else if (!strncmp(instruction, "sa", 3))
		sa(stack, 0);
	else if (!strncmp(instruction, "sb", 3))
		sb(stack, 0);
	else if (!strncmp(instruction, "ss", 3))
		ss(stack, 0);
	else if (!strncmp(instruction, "ra", 3))
		ra(stack, 0);
	else if (!strncmp(instruction, "rb", 3))
		rb(stack, 0);
	else if (!strncmp(instruction, "rr", 3))
		rr(stack, 0);
	else if (!strncmp(instruction, "rra", 3))
		rra(stack, 0);
	else if (!strncmp(instruction, "rrb", 3))
		rrb(stack, 0);
	else if (!strncmp(instruction, "rrr", 3))
		rrr(stack, 0);
	else
		return (1);
	return (0);
}

static	char	read_instrucitons(t_stack *stack)
{
	char	*instruction;
	char	*trimed_str;
	char	flag;

	flag = 0;
	instruction = NULL;
	trimed_str = NULL;
	while (1)
	{
		instruction = get_next_line(STDIN_FILENO);
		if (!instruction && !flag)
			return (free(trimed_str), 1);
		else if (!instruction)
			break ;
		flag = 1;
		trimed_str = ft_strtrim(instruction, " \n");
		free(instruction);
		if (ft_strlen(trimed_str) < 2 || ft_strlen(trimed_str) > 3)
			return (1);
		if (check_apllay(stack, trimed_str))
			return (1);
		free(trimed_str);
	}
	return (0);
}

static	void	fill_stack(t_stack **stack, char **args)
{
	int	i;

	*stack = NULL;
	*stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!*stack)
		exit(-1);
	(**stack).a = (int *)ft_calloc(arr_len(args), sizeof(int));
	if (!(**stack).a)
		exit(-1);
	(**stack).b = (int *)ft_calloc(arr_len(args), sizeof(int));
	if (!(**stack).b)
		exit(-1);
	(**stack).a_len = arr_len(args);
	i = 0;
	while (i < (**stack).a_len)
	{
		(**stack).a[i] = ft_atoi(args[i]);
		free(args[i]);
		i++;
	}
	free(args);
}

static	int	sorted(t_stack *stack)
{
	int	i;

	if (stack->b_len)
		return (0);
	i = 0;
	while (i < stack->a_len - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**arguments;
	t_stack	*stack;

	if (ac > 1)
	{
		arguments = NULL;
		arguments = parsing(ac, av);
		if (!arguments)
			return (-1);
		fill_stack(&stack, arguments);
		if (sorted(stack))
			ft_printf("\033[1;32mOK\033[0m\n");
		else
		{
			if (read_instrucitons(stack))
				ft_putstr_fd("\033[4;31merror\033[0m\n", 2);
			else if (sorted(stack))
				ft_printf("\033[1;32mOK\033[0m\n");
			else
				ft_printf("\033[4;31mKO\033[0m\n");
		}
		free_stack(stack);
	}
	return (0);
}

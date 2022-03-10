/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:23:37 by haitkadi          #+#    #+#             */
/*   Updated: 2022/03/06 14:23:39 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_is_empty(int ac, char **av)
{
	int	i;
	int	j;
	int	res;

	i = 1;
	while (i < ac)
	{
		if (!ft_strlen(av[i]))
			return (1);
		else
		{
			j = 0;
			res = 0;
			while (av[i][j])
				if (av[i][j++] != ' ')
					res++;
			if (!res)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_dup(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_max_int(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (ft_atoli(av[i]) > 2147483647 || ft_atoli(av[i]) < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

static	int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	check_is_number(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		if (av[i][j])
		{
			while (ft_isspace(av[i][j]))
				j++;
			if (!ft_isdigit(av[i][j]) && !ft_strchr("-+", av[i][j++]))
				return (1);
			else
			{
				while (av[i][j] && ft_isdigit(av[i][j]))
					j++;
				if (av[i][j] != 0)
					return (1);
			}
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:03:39 by haitkadi          #+#    #+#             */
/*   Updated: 2022/03/03 17:03:43 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**arguments;

	if (ac < 2)
		return (0);
	arguments = parsing(ac, av);
	if (!arguments)
		return (0);
	recipe(arguments);
	return (0);
}

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
	char	**args;

	args = parsing(ac, av);
	while (*args)
		ft_printf("args:%s\n", *args++);
	if (check_dup(ac, av))
		ft_printf("Error: duplicate found\n");
	else
		ft_printf("nothing found\n");
	if (check_max_int(ac, av))
		ft_printf("int overflow\n");
	else
		ft_printf("ok\n");
	if (check_is_int(ac, av))
		ft_printf("none integer\n");
	else
		ft_printf("ok\n");
	return (0);
}

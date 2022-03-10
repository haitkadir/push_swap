/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:07:08 by haitkadi          #+#    #+#             */
/*   Updated: 2022/03/04 19:07:12 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	handle_input_errs(int len, char **args)
{
	if (!args)
		return (ft_printf("\033[1;31mError:\033[4;31mAllocation faild\033[0m\n"), \
		1);
	if (check_is_number(len, args))
		return (ft_printf("\033[1;31mError:\033[4;31mNone integer value\033[0m\n"), \
		1);
	if (check_dup(len, args))
		return (ft_printf("\033[1;31mError:\033[4;31mDuplicate found\033[0m\n"), 1);
	if (check_max_int(len, args))
		return (ft_printf("\033[1;31mError:\033[4;31mInt overflow\033[0m\n"), 1);
	return (0);
}

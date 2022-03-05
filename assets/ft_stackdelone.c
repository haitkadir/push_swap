/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:42:23 by haitkadi          #+#    #+#             */
/*   Updated: 2021/11/15 15:42:25 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../src/push_swap.h"

void	ft_stackdelone(t_stack *lst)
{
	if (lst == NULL)
		return ;
	if (lst->content)
		free(lst->content);
	free(lst);
}

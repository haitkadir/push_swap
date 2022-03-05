/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:33:05 by haitkadi          #+#    #+#             */
/*   Updated: 2021/11/14 17:33:15 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../src/push_swap.h"

t_stack	*ft_stacknew(void *content)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		return (0);
	temp->prev = NULL;
	temp->content = content;
	temp->next = NULL;
	return (temp);
}

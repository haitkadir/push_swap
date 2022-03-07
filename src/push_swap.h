/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:03:26 by haitkadi          #+#    #+#             */
/*   Updated: 2022/03/03 17:03:29 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../assets/libft/libft.h"
# include "../assets/ft_printf/ft_printf.h"

typedef struct t_stack
{
	struct t_stack	*prev;
	int				*content;
	struct t_stack	*next;
}	t_stack;
/*-------------------------------- Assets -----------------------------------*/
t_stack	*ft_stacknew(void *content);
void	ft_stackadd(t_stack **lst, t_stack *new);
int		ft_stacksize(t_stack *lst);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_stackdelone(t_stack *lst);
/*-------------------------------- Source -----------------------------------*/
/*-------------------------------- Parsing ----------------------------------*/
char	**parsing(int ac, char **av);
/*-------------------------------- Error ------------------------------------*/
int		check_is_empty(int ac, char **av);
int		check_dup(int ac, char **av);
long	ft_atoli(const char *str);
int		check_max_int(int ac, char **av);
int		check_is_int(int ac, char **av);
int		handle_input_errs(int ac, char **args);
/*------------------------------- Free memory --------------------------------*/
void	free_2d_arr(char **arr);
#endif

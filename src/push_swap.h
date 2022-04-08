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
# include <limits.h>
# include <stdlib.h>
# include "../assets/libft/libft.h"
# include "../assets/ft_printf/ft_printf.h"

/*================================ Source ===================================*/

typedef struct t_stack
{
	int	*a;
	int	a_len;
	int	pivot_a;
	int	a_chunck_min;
	int	a_chunck_max;

	int	*b;
	int	b_len;
	int	pivot_b;
	int	b_chunck_min;
	int	b_chunck_max;
}	t_stack;

/*-------------------------------- Parsing ----------------------------------*/
char	**parsing(int ac, char **av);
int		arr_len(char **arr);
/*-------------------------------- Error ------------------------------------*/
int		check_is_empty(int ac, char **av);
int		check_dup(int ac, char **av);
long	ft_atol(const char *str);
int		check_max_int(int ac, char **av);
int		check_is_number(int ac, char **av);
int		handle_input_errs(int ac, char **args);
/*------------------------------- Free memory --------------------------------*/
void	free_2d_arr(char **arr);
void	free_stack(t_stack *stack);
/*------------------------------- instructions -------------------------------*/
void	swap(int *a, int *b);
int		shift_a(t_stack *stack);
int		rshift_a(t_stack *stack);
int		shift_b(t_stack *stack);
int		rshift_b(t_stack *stack);

void	sa(t_stack *stack, char flag);
void	sb(t_stack *stack, char flag);
void	ss(t_stack *stack, char flag);
void	pb(t_stack *stack, char flag);
void	pa(t_stack *stack, char flag);
void	ra(t_stack *stack, char flag);
void	rb(t_stack *stack, char flag);
void	rr(t_stack *stack, char flag);
void	rra(t_stack *stack, char flag);
void	rrb(t_stack *stack, char flag);
void	rrr(t_stack *stack, char flag);
/*------------------------------- Sorting algorithm --------------------------*/
int		get_midpoint_a(t_stack *stack, int chanck_len, int fixed_len);
int		get_midpoint_b(t_stack *stack, int chanck_len, int fixed_len);
int		is_sorted_a(t_stack *stack, int fixed_len);
/*------------------------------- Push to B ---------------------------------*/
int		n_to_pb(t_stack *stack, int len);
int		best_move_a(t_stack *stack);
void	push_b(t_stack *stack, int len, int fixed_len);

/*------------------------------- Push to A ---------------------------------*/
int		n_to_pa(t_stack *stack, int len);
int		best_move_b(t_stack *stack);
void	push_a(t_stack *stack, int len, int fixed_len);
/*------------------------------- quicksort ---------------------------------*/
void	quicksort(t_stack *stack);
/*------------------------------- The recipe ---------------------------------*/
int		recipe(char **args);
#endif

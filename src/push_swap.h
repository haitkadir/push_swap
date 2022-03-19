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

/*================================ Source ===================================*/

typedef struct t_stack
{
	int	*a;
	int	a_len;
	int	pivot_a;
	int	track_a;
	int	*b;
	int	b_len;
	int	pivot_b;
	int	track_b;
}	t_stack;

/*-------------------------------- Parsing ----------------------------------*/
char	**parsing(int ac, char **av);
int		arr_len(char **arr);
/*-------------------------------- Error ------------------------------------*/
int		check_is_empty(int ac, char **av);
int		check_dup(int ac, char **av);
long	ft_atoli(const char *str);
int		check_max_int(int ac, char **av);
int		check_is_number(int ac, char **av);
int		handle_input_errs(int ac, char **args);
/*------------------------------- Free memory --------------------------------*/
void	free_2d_arr(char **arr);
/*------------------------------- instructions -------------------------------*/
int		shift_a(t_stack *stack);
int		rshift_a(t_stack *stack);
int		shift_b(t_stack *stack);
int		rshift_b(t_stack *stack);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pb(t_stack *stack);
void	pa(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);
/*------------------------------- Sorting algorithm --------------------------*/
int		get_midpoint(int *arr, int size);
int		sorted(int *arr, int len);
/*------------------------------- Push to B ---------------------------------*/
int		n_to_pb(t_stack *stack, int len);
int		best_move_a(t_stack *stack);
void	push_b(t_stack *stack, int len);

/*------------------------------- Push to A ---------------------------------*/
void	push_a(t_stack *stack, int len);
int		n_to_pa(t_stack *stack, int len);
void	quicksort(t_stack *stack);
int		best_move_b(t_stack *stack);
/*------------------------------- The recipe ---------------------------------*/
int		recipe(char **args);
#endif

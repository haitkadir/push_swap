// #include "../src/push_swap.h"

// static void check_apllay(t_stack *stack, char *instruction)
// {
// 	if (ft_strncmp(instruction, ""))
		
// }

// static void read_instrucitons(t_stack *stack)
// {
// 	char *instruction;
// 	char *trimed_str;

// 	instruction = NULL;
// 	trimed_str = NULL;
// 	while (1)
// 	{
// 		instruction = get_next_line(0);
// 		if (!instruction)
// 			break ;
// 		trimed_str = ft_strtrim(instruction, ' ');

// 	}
// }

// static	void	fill_stack(t_stack *stack, char **args)
// {
// 	int	i;

// 	i = 0;
// 	while (i < stack->a_len)
// 	{
// 		stack->a[i] = ft_atoi(args[i]);
// 		i++;
// 	}
// }

// static void manage_checker(char **args)
// {
// 	t_stack	*stack;

// 	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
// 	stack->a = (int *)ft_calloc(arr_len(args), sizeof(int));
// 	stack->b = (int *)ft_calloc(arr_len(args), sizeof(int));
// 	stack->a_len = arr_len(args);
// 	stack->b_len = 0;
// 	fill_stack(stack, args);
// 	free_2d_arr(args);
// }

// int main(int ac, char **av)
// {
// 	char	**arguments;

// 	arguments = parsing(ac, av);
// 	if (!arguments)
// 		return (-1);
//     manage_checker(arguments);
//     return (0);
// }
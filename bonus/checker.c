#include "../src/push_swap.h"
#include "./gnl/get_next_line.h"

static void check_apllay(t_stack *stack, char *instruction)
{
	if (ft_strncmp(instruction, "pa", 2))
        pa(stack, 0);
    else if (ft_strncmp(instruction, "pb", 2))
        pb(stack, 0);
    else if (ft_strncmp(instruction, "sa", 2))
        sa(stack, 0);
    else if (ft_strncmp(instruction, "sb", 2))
        sb(stack, 0);
    else if (ft_strncmp(instruction, "ss", 2))
        ss(stack, 0);
    else if (ft_strncmp(instruction, "ra", 2))
        ra(stack, 0);
    else if (ft_strncmp(instruction, "rb", 2))
        rb(stack, 0);
    else if (ft_strncmp(instruction, "rr", 2))
        rr(stack, 0);
    else if (ft_strncmp(instruction, "rra", 3))
        rra(stack, 0);
    else if (ft_strncmp(instruction, "rrb", 3))
        rrb(stack, 0);
    else if (ft_strncmp(instruction, "rrr", 3))
        rrr(stack, 0);
    else
        ft_putstr_fd("error\n", 2);
}

static void read_instrucitons(t_stack *stack)
{
	char *instruction;
	char *trimed_str;

	instruction = NULL;
	trimed_str = NULL;
	while (1)
	{
		instruction = get_next_line(STDIN_FILENO);
		if (!instruction)
			break ;
		trimed_str = ft_strtrim(instruction, " \n");
        check_apllay(stack, trimed_str);
        free(trimed_str);
	}
}

static	void	fill_stack(t_stack *stack, char **args)
{
	int	i;

	i = 0;
	while (i < stack->a_len)
	{
		stack->a[i] = ft_atoi(args[i]);
		free(args[i]);
		i++;
	}
	free(args);
}

static int sorted(t_stack *stack)
{
	int	i;

	if (stack->b_len)
		return (0);
	i = 0;
	while (i < stack->a_len - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	char	**arguments;
	t_stack	*stack;

	arguments = parsing(ac, av);
	if (!arguments)
		return (-1);
	stack = NULL;
    stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack->a = (int *)ft_calloc(arr_len(args), sizeof(int));
	stack->b = (int *)ft_calloc(arr_len(args), sizeof(int));
	stack->a_len = arr_len(args);
	fill_stack(stack, args);
	read_instrucitons(stack);
	if (sorted(stack))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (stack)
		free(stack);
    return (0);
}
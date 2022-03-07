#include "push_swap.h"

static	int	arr_len(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			i++;
	}
	return (i);
}

static	void	free_allocation(char *tmp, char *tmp2, char *result)
{
	if (tmp)
		free(tmp);
	if (tmp2)
		free(tmp2);
	if (result)
		free(result);
}

static char	**join_args(int ac, char **av)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*result;

	tmp = NULL;
	tmp2 = NULL;
	result = NULL;
	i = 1;
	while (i < ac)
	{
		tmp = ft_strjoin(av[i], " ");
		if (!tmp)
			return (free_allocation(tmp, tmp2, result), NULL);
		tmp2 = result;
		result = NULL;
		if (tmp2)
			result = ft_strjoin(tmp2, tmp);
		else
			result = ft_strdup(tmp);
		if (!result)
			return (free_allocation(tmp, tmp2, result), NULL);
		i++;
	}
	return (free_allocation(tmp, tmp2, result), ft_split(result, ' '));
}

char	**parsing(int ac, char **av)
{
	char	**args;

	args = NULL;
	if (check_is_empty(ac, av))
		return (ft_printf("\033[1;31mError:\033[4;31mEmpty argument\033[0m\n"),
			NULL);
	args = join_args(ac, av);
	if (handle_input_errs(arr_len(args), args))
		free_2d_arr(args);
	return (NULL);
}

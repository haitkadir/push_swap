#include "push_swap.h"

char	**parsing(int ac, char **av)
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
		tmp2 = result;
		if (tmp2)
			result = ft_strjoin(tmp2, tmp);
		else
			result = ft_strdup(tmp);
		if (tmp2)
			free(tmp2);
		if (tmp)
			free(tmp);
		i++;
	}
	return (ft_split(result, ' '));
}

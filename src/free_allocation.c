#include "push_swap.h"

void	free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			ft_printf("\033[1;33mDebug\033[0m\n");
			if (arr[i])
				free(arr[i]);
			i++;
		}
		free(arr);
	}
}

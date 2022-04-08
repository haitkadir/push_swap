/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+::+:          :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:37:16 by haitkadi          #+#    #+#             */
/*   Updated: 2021/11/22 21:37:21 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*read_from_fd(int fd, char *buf, char *line)
{
	int		ret;
	char	*tmp;

	ret = 0;
	while (1)
	{
		ret = read(fd, buf, 1);
		if (ret <= 0)
			break ;
		if (line)
		{
			tmp = line;
			line = NULL;
			line = ft_strjoin(tmp, buf);
			free(tmp);
		}
		else
			line = ft_strdup(buf);
		if (!line)
			exit(-1);
		if (buf[0] == '\n')
			break ;
		buf[0] = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*buf;

	buf = NULL;
	line = NULL;
	buf = (char *)ft_calloc(2, sizeof(char));
	if (!buf)
		exit(-1);
	line = read_from_fd(fd, buf, line);
	free(buf);
	return (line);
}

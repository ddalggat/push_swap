/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:30:31 by gjailbir          #+#    #+#             */
/*   Updated: 2021/10/06 23:30:32 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_check_tail(char **tail, char **line)
{
	char	*mark;

	mark = NULL;
	if (*tail)
	{
		mark = ft_strchr(*tail, '\n');
		if (mark)
		{
			*mark = '\0';
			*line = *tail;
			*tail = ft_strdup(++mark);
		}
		else
		{
			*line = *tail;
			*tail = 0;
		}
	}
	else
		*line = ft_calloc_V2(1);
	return (mark);
}

int	read_line(char **line, char **tail, char *buff, int fd)
{
	int		cnt_byte;
	char	*mark;
	char	*mark2;

	cnt_byte = 1;
	mark = ft_check_tail(tail, line);
	while (mark == NULL && cnt_byte)
	{
		cnt_byte = read(fd, buff, BUFFER_SIZE);
		buff[cnt_byte] = '\0';
		mark = ft_strchr(buff, '\n');
		if (mark)
		{
			 *mark = '\0';
			 *tail = ft_strdup(++mark);
		}
		mark2 = *line;
		*line = ft_strjoin(*line, buff);
		free(mark2);
	}
	free(buff);
	if (*tail || cnt_byte)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*tail;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (-1);
	if (read(fd, buff, 0) == -1)
	{
		free(buff);
		return (-1);
	}
	if (read_line(line, &tail, buff, fd))
		return (1);
	return (0);
}

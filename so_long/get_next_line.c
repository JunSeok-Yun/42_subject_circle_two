/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:55:17 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/26 15:13:24 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_nextline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	read_line(char **buffer, char **res, int line_idx)
{
	int		str_len;
	char	*temp;

	(*buffer)[line_idx] = 0;
	*res = ft_strdup(*buffer);
	str_len = ft_strlen(*buffer + line_idx + 1);
	if (str_len == 0)
	{
		free(*buffer);
		*buffer = 0;
		return (1);
	}
	temp = ft_strdup(*buffer + line_idx + 1);
	free(*buffer);
	*buffer = temp;
	return (1);
}

static int	end_line(char **buffer, char **res, int size)
{
	int	line_idx;

	if (size < 0)
		return (-1);
	if (*buffer)
	{
		line_idx = check_nextline(*buffer);
		if (line_idx > 0)
			return (read_line(buffer, res, line_idx));
		else
		{
			*res = *buffer;
			*buffer = 0;
			return (0);
		}
	}
	*res = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **res)
{
	static char	*buffer[FD_MAX];
	char		read_buf[BUFFER_SIZE + 1];
	int			size;
	int			line_idx;

	if (BUFFER_SIZE <= 0 || fd < 0 || res == 0)
		return (-1);
	size = read(fd, read_buf, BUFFER_SIZE);
	while (size > 0)
	{
		read_buf[size] = 0;
		buffer[fd] = ft_strjoin(buffer[fd], read_buf);
		line_idx = check_nextline(buffer[fd]);
		if (line_idx >= 0)
			return (read_line(&buffer[fd], res, line_idx));
		size = read(fd, read_buf, BUFFER_SIZE);
	}
	return (end_line(&buffer[fd], res, size));
}

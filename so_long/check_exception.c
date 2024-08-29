/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exception.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:54:22 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/26 14:59:37 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_component(t_vals *vals, char c, int y, int x)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C')
	{
		if (c == 'P')
		{
			vals->cnt_p += 1;
			vals->x = x;
			vals->y = y;
		}
		else if (c == 'E')
			vals->cnt_e += 1;
		else if (c == 'C')
			vals->cnt_c += 1;
		return (1);
	}
	else
		return (0);
}

int	check_map_component_cnt(t_vals *vals, int i, int j)
{
	char	c;

	c = 0;
	while (i < vals->height)
	{
		j = 0;
		while (j < vals->width)
		{
			c = vals->map[i][j];
			if (check_map_component(vals, c, i, j) == 1)
				j++;
			else
				return (0);
		}
		i++;
	}
	if ((vals->cnt_c >= 1) && (vals->cnt_e == 1) && (vals->cnt_p == 1))
		return (1);
	return (0);
}

int	res_check_map_width(t_vals *vals, int *arr)
{
	int	j;

	j = 0;
	while (j < vals->height)
	{
		if (arr[j] != vals->width)
		{
			free(arr);
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_map_width(t_vals *vals, int i, int j)
{
	int		fd;
	int		*arr;
	char	*res;

	arr = (int *)malloc(sizeof(int) * (vals->height + 1));
	fd = open(vals->file_name, O_RDONLY);
	i = get_next_line(fd, &res);
	vals->width = ft_strlen(res);
	while (i != 0)
	{
		arr[j++] = ft_strlen(res);
		free(res);
		i = get_next_line(fd, &res);
	}
	if (res[0] != 0)
		arr[j++] = ft_strlen(res);
	arr[j] = 0;
	free(res);
	if (!(res_check_map_width(vals, arr)))
		return (0);
	free(arr);
	return (1);
}

int	check_map_row_col(t_vals *vals, int i)
{
	int		fd;
	int		height;
	char	*res;

	fd = open(vals->file_name, O_RDONLY);
	i = get_next_line(fd, &res);
	height = 0;
	while (i != 0)
	{
		free(res);
		i = get_next_line(fd, &res);
		height++;
	}
	if (res[0] != 0)
		height++;
	free(res);
	close(fd);
	if (height <= 2)
		return (0);
	vals->height = height;
	if (!(check_map_width(vals, 0, 0)))
		return (0);
	return (1);
}

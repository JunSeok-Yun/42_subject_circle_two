/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exception2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:54:41 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/24 21:54:45 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_wall(t_vals *vals)
{
	int	i;
	int	j;

	i = 0;
	while (i < vals->height)
	{
		if (i == 0 || i == vals->height - 1)
		{
			j = 0;
			while (j < vals->width)
			{
				if (vals->map[i][j] != '1')
					error_free_exception("map wall Error!!\n", vals);
				j++;
			}
		}
		else
		{
			if (vals->map[i][0] != '1' || vals->map[i][vals->width - 1] != '1')
				error_free_exception("map wall Error!!\n", vals);
		}
		i++;
	}
}

void	init_map(t_vals *vals)
{
	int		i;
	int		fd;
	char	*res;

	i = 0;
	fd = open(vals->file_name, O_RDONLY);
	vals->map = (char **)malloc(sizeof(char *) * vals->height);
	while (i < vals->height)
	{
		get_next_line(fd, &res);
		vals->map[i] = ft_strdup(res);
		free(res);
		i++;
	}
}

int	check_map(t_vals *vals)
{
	if (!(check_map_row_col(vals, 0)))
		error_exception(vals, "Wrong Row and Col!!\n");
	init_map(vals);
	vals->fd = open(vals->file_name, O_RDONLY);
	if (!(check_map_component_cnt(vals, 0, 0)))
		error_free_exception("component cnt Error!!\n", vals);
	check_map_wall(vals);
	check_map_dfs(vals);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:54:46 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/26 15:47:20 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**init_visited_map(t_vals *vals)
{
	int		**visited;
	int		i;
	int		j;

	i = 0;
	visited = (int **)malloc(sizeof(int *) * (vals->height));
	if (!(visited))
		return (0);
	while (i < vals->height)
	{
		visited[i] = (int *)malloc(sizeof(int) * (vals->width));
		if (!(visited[i]))
		{
			free_visited(vals, visited);
			return (0);
		}
		j = 0;
		while (j < vals->width)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	return (visited);
}

void	create_visited_map(t_vals *vals, t_visited *visited_map)
{
	visited_map->visited = init_visited_map(vals);
	visited_map->x = vals->width;
	visited_map->y = vals->height;
	visited_map->c_cnt = vals->cnt_c;
}

static void	dx_dy_setup(t_vals *vals)
{
	vals->dx[0] = 1;
	vals->dx[1] = -1;
	vals->dx[2] = 0;
	vals->dx[3] = 0;
	vals->dy[0] = 0;
	vals->dy[1] = 0;
	vals->dy[2] = 1;
	vals->dy[3] = -1;
}

void	dfs(t_vals *vals, t_visited *visited_map, int x, int y)
{
	int		nx;
	int		ny;
	int		i;

	dx_dy_setup(vals);
	visited_map->visited[y][x] = 1;
	if (vals->map[y][x] == 'C')
		visited_map->c_cnt -= 1;
	if (vals->map[y][x] == 'E')
	{
		vals->flag = 1;
		return ;
	}
	i = 0;
	while (i < 4)
	{
		nx = x + vals->dx[i];
		ny = y + vals->dy[i];
		if (vals->map[ny][nx] != '1' && !(visited_map->visited[ny][nx]) && \
				nx >= 0 && nx < vals->width && ny >= 0 && ny < vals->height)
			dfs(vals, visited_map, nx, ny);
		i++;
	}
}

void	check_map_dfs(t_vals *vals)
{
	t_visited	visited_map;

	create_visited_map(vals, &visited_map);
	dfs(vals, &visited_map, vals->x, vals->y);
	if (!(vals->flag) || visited_map.c_cnt != 0)
	{
		free_visited(vals, visited_map.visited);
		free_vals(vals);
		error_exception(vals, "dfs validation fail!! check map!!\n");
	}
	free_visited(vals, visited_map.visited);
}

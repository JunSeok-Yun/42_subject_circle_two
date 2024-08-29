/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:54:55 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/26 15:11:30 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_vals(t_vals *vals)
{
	int	i;

	i = 0;
	while (i < vals->height)
	{
		free(vals->map[i]);
		i++;
	}
	free(vals->map);
}

void	free_visited(t_vals *vals, int **visited)
{
	int	i;

	i = 0;
	while (i < vals->height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
	visited = 0;
}

void	destroy_img(t_vals *vals)
{
	mlx_destroy_image(vals->mlx_ptr, vals->game_img);
	mlx_destroy_image(vals->mlx_ptr, vals->collection_img);
	mlx_destroy_image(vals->mlx_ptr, vals->player_img);
	mlx_destroy_image(vals->mlx_ptr, vals->exit_img);
	mlx_destroy_image(vals->mlx_ptr, vals->wall_img);
}

int	destroy_map(t_vals *vals)
{
	destroy_img(vals);
	mlx_destroy_window(vals->mlx_ptr, vals->win_ptr);
	mlx_destroy_display(vals->mlx_ptr);
	free(vals->mlx_ptr);
	free_vals(vals);
	exit(1);
}

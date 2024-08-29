/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:07:48 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/26 15:10:02 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_game_map(t_vals *vals, char map_c, int x, int y)
{
	mlx_put_image_to_window(vals->mlx_ptr, vals->win_ptr, vals->game_img, \
			x, y);
	if (map_c == '1')
		mlx_put_image_to_window(vals->mlx_ptr, vals->win_ptr, vals->wall_img, \
				x, y);
	else if (map_c == 'P')
		mlx_put_image_to_window(vals->mlx_ptr, vals->win_ptr, vals->player_img, \
				x, y);
	else if (map_c == 'C')
		mlx_put_image_to_window(vals->mlx_ptr, vals->win_ptr, \
				vals->collection_img, x, y);
	else if (map_c == 'E')
		mlx_put_image_to_window(vals->mlx_ptr, vals->win_ptr, vals->exit_img, \
				x, y);
}

void	drawing_map(t_vals *vals)
{
	int	i;
	int	j;

	mlx_clear_window(vals->mlx_ptr, vals->win_ptr);
	i = 0;
	while (i < vals->height)
	{
		j = 0;
		while (j < vals->width)
		{
			draw_game_map(vals, vals->map[i][j], j * vals->img_pixel, \
					i * vals->img_pixel);
			j++;
		}
		i++;
	}
}

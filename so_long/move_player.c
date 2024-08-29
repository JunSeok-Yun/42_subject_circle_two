/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:14:51 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/26 15:18:27 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

void	w_key_press(t_vals *vals)
{
	if (vals->map[vals->y - 1][vals->x] == '1')
		return ;
	else if (vals->map[vals->y - 1][vals->x] == 'E')
	{
		if (vals->cnt_c == 0)
			destroy_map(vals);
		else
			return ;
	}
	else if (vals->map[vals->y - 1][vals->x] == 'C')
		vals->cnt_c--;
	vals->map[vals->y][vals->x] = '0';
	vals->map[vals->y - 1][vals->x] = 'P';
	vals->cnt++;
	vals->y--;
	ft_printf("cur move count = %d\n", vals->cnt);
}

void	a_key_press(t_vals *vals)
{
	if (vals->map[vals->y][vals->x - 1] == '1')
		return ;
	else if (vals->map[vals->y][vals->x - 1] == 'E')
	{
		if (vals->cnt_c == 0)
			destroy_map(vals);
		else
			return ;
	}
	else if (vals->map[vals->y][vals->x - 1] == 'C')
		vals->cnt_c--;
	vals->map[vals->y][vals->x] = '0';
	vals->map[vals->y][vals->x - 1] = 'P';
	vals->cnt++;
	vals->x--;
	ft_printf("cur move count = %d\n", vals->cnt);
}

void	s_key_press(t_vals *vals)
{
	if (vals->map[vals->y + 1][vals->x] == '1')
		return ;
	else if (vals->map[vals->y + 1][vals->x] == 'E')
	{
		if (vals->cnt_c == 0)
			destroy_map(vals);
		else
			return ;
	}
	else if (vals->map[vals->y + 1][vals->x] == 'C')
		vals->cnt_c--;
	vals->map[vals->y][vals->x] = '0';
	vals->map[vals->y + 1][vals->x] = 'P';
	vals->cnt++;
	vals->y++;
	ft_printf("cur move count = %d\n", vals->cnt);
}

void	d_key_press(t_vals *vals)
{
	if (vals->map[vals->y][vals->x + 1] == '1')
		return ;
	else if (vals->map[vals->y][vals->x + 1] == 'E')
	{
		if (vals->cnt_c == 0)
			destroy_map(vals);
		else
			return ;
	}
	else if (vals->map[vals->y][vals->x + 1] == 'C')
		vals->cnt_c--;
	vals->map[vals->y][vals->x] = '0';
	vals->map[vals->y][vals->x + 1] = 'P';
	vals->cnt++;
	vals->x++;
	ft_printf("cur move count = %d\n", vals->cnt);
}

int	move_player(int key_code, t_vals *vals)
{
	if (key_code == W_KEY)
		w_key_press(vals);
	else if (key_code == A_KEY)
		a_key_press(vals);
	else if (key_code == S_KEY)
		s_key_press(vals);
	else if (key_code == D_KEY)
		d_key_press(vals);
	else if (key_code == ESC_KEY)
		destroy_map(vals);
	else
		return (0);
	drawing_map(vals);
	return (1);
}

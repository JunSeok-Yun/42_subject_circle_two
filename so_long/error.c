/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:54:51 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/24 21:54:54 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_str(char *str)
{
	write(1, str, (int)ft_strlen(str));
}

void	error_print(char *str)
{
	ft_put_str(str);
	exit(1);
}

void	error_exception(t_vals *vals, char *str)
{
	ft_put_str(str);
	destroy_img(vals);
	mlx_destroy_display(vals->mlx_ptr);
	free(vals->mlx_ptr);
	exit(1);
}

void	error_free_exception(char *str, t_vals *vals)
{
	ft_put_str(str);
	destroy_img(vals);
	mlx_destroy_display(vals->mlx_ptr);
	free(vals->mlx_ptr);
	free_vals(vals);
	exit(1);
}

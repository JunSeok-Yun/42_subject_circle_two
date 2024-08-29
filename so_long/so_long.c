/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:55:39 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/26 15:35:21 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_filename(char *argv)
{
	size_t	i;

	i = ft_strlen(argv);
	if (i < 5)
		return (0);
	if (argv[i - 4] != '.' || argv[i - 3] != 'b' || argv[i - 2] != 'e' || \
		argv[i - 1] != 'r')
		return (0);
	return (1);
}

static void	setup_vals(t_vals *vals, char *argv)
{
	int	img_size;
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_print("open_file Error!!\n");
	close(fd);
	vals->file_name = argv;
	vals->cnt = 0;
	vals->cnt_p = 0;
	vals->cnt_c = 0;
	vals->cnt_e = 0;
	vals->img_pixel = 64;
	vals->flag = 0;
	vals->mlx_ptr = mlx_init();
	vals->game_img = mlx_xpm_file_to_image(vals->mlx_ptr, \
			"textures/0.xpm", &img_size, &img_size);
	vals->wall_img = mlx_xpm_file_to_image(vals->mlx_ptr, \
			"textures/1.xpm", &img_size, &img_size);
	vals->player_img = mlx_xpm_file_to_image(vals->mlx_ptr, \
			"textures/P.xpm", &img_size, &img_size);
	vals->collection_img = mlx_xpm_file_to_image(vals->mlx_ptr, \
			"textures/C.xpm", &img_size, &img_size);
	vals->exit_img = mlx_xpm_file_to_image(vals->mlx_ptr, \
			"textures/E.xpm", &img_size, &img_size);
}

int	main(int argc, char *argv[])
{
	t_vals	vals;

	if (argc != 2 || argv[1] == 0)
		error_print("Argument Error!!\n");
	if (!check_filename(argv[1]))
		error_print("File_name Error!!\n");
	setup_vals(&vals, argv[1]);
	check_map(&vals);
	vals.win_ptr = mlx_new_window(vals.mlx_ptr, vals.img_pixel * vals.width, \
		vals.img_pixel * vals.height, "junseok so_long");
	drawing_map(&vals);
	mlx_hook(vals.win_ptr, KeyPress, KeyPressMask, &move_player, &vals);
	mlx_hook(vals.win_ptr, DestroyNotify, KeyPressMask, &destroy_map, &vals);
	mlx_loop(vals.mlx_ptr);
	free_vals(&vals);
	return (0);
}

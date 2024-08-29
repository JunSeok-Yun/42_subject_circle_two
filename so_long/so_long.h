/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:56:03 by junseyun          #+#    #+#             */
/*   Updated: 2024/08/26 15:40:50 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define BUFFER_SIZE 	32
# define FD_MAX 		1024
# define ESC_KEY		65307
# define W_KEY			119
# define A_KEY			97
# define S_KEY			115
# define D_KEY			100

typedef struct s_vals
{
	char	*file_name;
	char	**map;
	int		fd;
	int		height;
	int		width;
	int		x;
	int		y;
	int		cnt;
	int		cnt_p;
	int		cnt_c;
	int		cnt_e;
	int		flag;
	int		img_pixel;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*game_img;
	void	*collection_img;
	void	*exit_img;
	void	*player_img;
	void	*wall_img;
	int		dx[4];
	int		dy[4];
}	t_vals;

typedef struct s_visited
{
	int	x;
	int	y;
	int	c_cnt;
	int	**visited;
}	t_visited;

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	*ft_strncpy(char *s1, char *s2, int n);
int		get_next_line(int fd, char **res);

void	error_print(char *str);
void	error_exception(t_vals *vals, char *str);
void	error_free_exception(char *str, t_vals *vals);
void	free_vals(t_vals *vals);
int		check_map(t_vals *vals);

int		check_map_component(t_vals *vals, char c, int y, int x);
int		check_map_component_cnt(t_vals *vals, int i, int j);
int		res_check_map_width(t_vals *vals, int *arr);
int		check_map_width(t_vals *vals, int i, int j);
int		check_map_row_col(t_vals *vals, int i);
void	init_map(t_vals *vals);
void	check_map_wall(t_vals *vals);

void	check_map_dfs(t_vals *vals);
void	create_visited_map(t_vals *vals, t_visited *visited_map);
void	dfs(t_vals *vals, t_visited *visited_map, int x, int y);
void	free_visited(t_vals *vals, int **visited);
int		**init_visited_map(t_vals *vals);

int		move_player(int key_code, t_vals *vals);
int		destroy_map(t_vals *vals);
void	destroy_img(t_vals *vals);
void	drawing_map(t_vals *vals);
void	draw_game_map(t_vals *vals, char map_c, int x, int y);

int		move_player(int key_code, t_vals *vals);
void	w_key_press(t_vals *vals);
void	a_key_press(t_vals *vals);
void	s_key_press(t_vals *vals);
void	d_key_press(t_vals *vals);

#endif

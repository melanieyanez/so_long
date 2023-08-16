/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 00:19:58 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/16 11:10:15 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"

# define WIDTH 1280
# define HEIGHT 720
# define SIZE 50

# define KEY_LEFT   123
# define KEY_RIGHT  124
# define KEY_DOWN   125
# define KEY_UP     126
# define KEY_ESCAPE 53
# define CLOSE		17

# define RED 	0x00FF0000
# define PURPLE 0x00800080
# define GREEN 	0x00008000
# define YELLOW 0x00FFFACD
# define PINK 	0x00FF69B4

/*_____________ Structures _______________________*/

typedef struct s_map
{
	char	*path;
	int		map_x;
	int		map_y;
}t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
}t_player;

typedef struct utils
{
	int	collect_counter;
	int	move_counter;
}t_utils;

typedef struct s_square
{
	int	start_x;
	int	start_y;
	int	size;
}t_square;

typedef struct s_vars
{
	void		*mlx;
	void		*wdw;
	char		**map_array;
	t_map		map;
	t_img		background;
	t_img		player;
	t_img		collectible;
	t_img		exit;
	t_img		wall;
	t_img		test;
	t_img		img;
	t_square	square;
}t_vars;

/*_____________ Functions _______________________*/

//checker.c

void	map_error(void);

//events.c

int		close_window(t_vars *vars);
int		mouse_actions(int key, t_vars *vars);
int		key_actions(int key, t_vars *vars);

//initialization.c

void	initialization(t_vars *vars, char *file_path);
void	map_size(t_vars *vars);

//parsing.c

void	line_interpreter(char *line);
void	map_parser(t_vars *vars);

//render.c

void	draw_background(t_vars *vars);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	drawing(t_vars *vars);
void	drawing_updated(t_vars *vars);

#endif
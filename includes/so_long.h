/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 00:19:58 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/22 09:57:19 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Passer toutes les variables dans utils et modifier le code en accord */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"

# define SIZE 50

# define KEY_LEFT   123
# define KEY_RIGHT  124
# define KEY_DOWN   125
# define KEY_UP     126
# define KEY_ESCAPE 53
# define CLOSE		17

# define WHITE	0xFFFFFF

/*_____________ Structures _______________________*/

typedef struct s_map
{
	char	*path;
	int		map_x;
	int		map_y;
	int		res_x;
	int		res_y;
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
	int		pos_x;
	int		pos_y;
	t_img	img;
	t_img	img_rev;
}t_player;

typedef struct utils
{
	int			rev;
	int			moves;
	int			start_found;
	int			to_collect;
	int			collected;
	int			exit_found;
	int			exit_unlocked;
	int			pos_exit;
	int			won;
	int			moving;
}t_utils;

typedef struct s_vars
{
	void		*mlx;
	void		*wdw;
	t_img		img;
	t_map		map;
	char		**map_array;
	t_img		background;
	t_img		wall;
	t_img		collectible;
	t_img		exit;
	t_player	player;
	int			rev;
	int			moves;
	int			start_found;
	int			to_collect;
	int			collected;
	int			exit_found;
	int			exit_unlocked;
	int			pos_exit;
	int			won;
	int			current_frame;
	void		*sprite_images[7];
	int			moving;
	t_utils		utils;
}t_vars;

/*_____________ Functions _______________________*/

//animation.c

void	fox_sprite(t_vars *vars, char *foxtype, int num_frames);

//checker.c

void	map_error(char *error_message);
void	map_checker(t_vars *vars);
void	extension_checker(t_vars *vars);
void	wall_checker(t_vars *vars);
void	path_checker(t_vars *vars);

//events.c

int		close_window(t_vars *vars);
void	player_pos(t_vars *vars, int pot_x, int pot_y);
int		key_press_actions(int key, t_vars *vars);
int		key_release_actions(int key, t_vars *vars);

//initialization.c

void	initialization(t_vars *vars, char *file_path);
void	map_size(t_vars *vars);
int		linelen(char *str);

//parsing.c

void	map_parser(t_vars *vars);
void	map_counter(t_vars *vars, char *line);

//render.c

void	draw_background(t_vars *vars);
void	draw_player(t_vars *vars);
void	drawing_updated(t_vars *vars);
int		render(t_vars *vars);
void	img_loading(t_vars *vars);
void	game_data(t_vars *vars);

#endif
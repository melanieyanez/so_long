/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 00:19:58 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/22 15:03:33 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		current_frame;
	void	*sprite_frames[7];
	t_img	img;
	t_img	img_rev;
	t_img	img_end;
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
	t_utils		utils;
}t_vars;

/*_____________ Functions _______________________*/

//animation.c

void	draw_player(t_vars *vars);
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
void	player_pos_ext(t_vars *vars, int *pot_x, int *pot_y);

//free.c

void	free_array(t_vars *vars);

//initialization.c

void	initialization(t_vars *vars, char *file_path);
void	img_loading(t_vars *vars);
void	img_addr(t_vars *vars);

//main.c

int		main(int argc, char **argv);
int		render(t_vars *vars);

//parsing.c

void	map_parser(t_vars *vars);
void	array_filler(t_vars *vars);
void	map_counter(t_vars *vars, char *line);
int		linelen(char *str);

//render.c

void	draw_background(t_vars *vars);
void	draw_objects(t_vars *vars);
void	game_data(t_vars *vars);
void	game_sentences(t_vars *vars);
void	line_interpreter(t_vars *vars, int *i, int *j);

#endif
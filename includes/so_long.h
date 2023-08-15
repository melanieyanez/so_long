/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 00:19:58 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/11 17:40:09 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "../mlx/mlx.h"

# define WIDTH 1280
# define HEIGHT 720

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

typedef struct img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

typedef struct player
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
	int start_x;
	int start_y;
	int	size;
}t_square;

typedef struct s_vars
{
	void		*mlx;
	void		*wdw;
	t_img		background;
	t_img		img;
	t_square	square;
}t_vars;

#endif
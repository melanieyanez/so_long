/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:00:40 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/22 23:50:13 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/so_long.h>

void	initialization(t_vars *vars, char *file)
{
	vars->map.path = ft_strdup(file);
	extension_checker(vars);
	map_parser(vars);
	vars->map.res_x = vars->map.map_x * SIZE;
	vars->map.res_y = vars->map.map_y * SIZE;
	vars->map_array = malloc(sizeof(char *) * vars->map.map_y);
	vars->player.pos_x = -1;
	vars->player.pos_y = -1;
	vars->utils.rev = 0;
	vars->utils.collected = 0;
	vars->utils.moves = 0;
	vars->utils.to_collect = 0;
	vars->utils.exit_unlocked = 0;
	vars->utils.won = 0;
	vars->utils.exit_found = 0;
	vars->utils.start_found = 0;
	vars->utils.pos_exit = 0;
	vars->player.current_frame = 0;
	vars->utils.moving = 0;
	vars->utils.exit_access = 0;
	vars->utils.collect_access = 0;
}

void	img_loading(t_vars *vars)
{
	vars->background.img = mlx_png_file_to_image(vars->mlx, \
		"imgs/background.png", &vars->background.line_length, \
		&vars->background.endian);
	vars->wall.img = mlx_png_file_to_image(vars->mlx, "imgs/tree.png", \
		&vars->wall.line_length, &vars->wall.endian);
	vars->player.img.img = mlx_png_file_to_image(vars->mlx, \
		"imgs/idle_fox_0.png", &vars->player.img.line_length, \
		&vars->player.img.endian);
	vars->player.img_rev.img = mlx_png_file_to_image(vars->mlx, \
		"imgs/idle_rev_fox_0.png", &vars->player.img_rev.line_length, \
		&vars->player.img_rev.endian);
	vars->player.img_end.img = mlx_png_file_to_image(vars->mlx, \
		"imgs/sleepy_fox_0.png", &vars->player.img_end.line_length, \
		&vars->player.img_end.endian);
	vars->collectible.img = mlx_png_file_to_image(vars->mlx, "imgs/rasp2.png", \
		&vars->collectible.line_length, &vars->collectible.endian);
	vars->exit.img = mlx_png_file_to_image(vars->mlx, "imgs/cave.png", \
		&vars->exit.line_length, &vars->exit.endian);
	if (vars->background.img == NULL || vars->wall.img == NULL
		|| vars->player.img.img == NULL || vars->player.img_rev.img == NULL
		|| vars->player.img_end.img == NULL || vars->collectible.img == NULL
		|| vars->exit.img == NULL)
		map_error("Image couldn't be loaded.\n");
	img_addr(vars);
}

void	img_addr(t_vars *vars)
{
	vars->background.addr = mlx_get_data_addr(vars->background.img, \
		&vars->background.bits_per_pixel, &vars->background.line_length, \
		&vars->background.endian);
	vars->wall.addr = mlx_get_data_addr(vars->wall.img, \
		&vars->wall.bits_per_pixel, &vars->wall.line_length, \
		&vars->wall.endian);
	vars->player.img.addr = mlx_get_data_addr(vars->player.img.img, \
		&vars->player.img.bits_per_pixel, &vars->player.img.line_length, \
		&vars->player.img.endian);
	vars->player.img_rev.addr = mlx_get_data_addr(vars->player.img_rev.img, \
		&vars->player.img_rev.bits_per_pixel, \
		&vars->player.img_rev.line_length, &vars->player.img_rev.endian);
	vars->player.img_end.addr = mlx_get_data_addr(vars->player.img_end.img, \
		&vars->player.img_end.bits_per_pixel, \
		&vars->player.img_end.line_length, &vars->player.img_end.endian);
	vars->collectible.addr = mlx_get_data_addr(vars->collectible.img, \
		&vars->collectible.bits_per_pixel, &vars->collectible.line_length, \
		&vars->collectible.endian);
	vars->exit.addr = mlx_get_data_addr(vars->exit.img, \
		&vars->exit.bits_per_pixel, &vars->exit.line_length, \
		&vars->exit.endian);
}

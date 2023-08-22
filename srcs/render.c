/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:18:39 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/22 11:56:14 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Ajouter une condition de taille minimum pour game data */
/* Renommer et réduire la fonction drawing updated */
/* Passer la fonction img loading dans initialization.c */
/* Réduire les lignes trop longues */
/* Ajouter la condition while (!won) */

#include "../includes/so_long.h"

void	draw_player(t_vars *vars)
{
	if (vars->utils.moving == 1 && vars->rev == 0 && vars->won == 0)
	{
		fox_sprite(vars, "imgs/moving_fox_", 8);
	}
	else if (vars->utils.moving == 1 && vars->rev == 1 && vars->won == 0)
	{
		fox_sprite(vars, "imgs/moving_rev_fox_", 8);
	}
	else if (vars->utils.moving == 0 && vars->rev == 0 && vars->won == 0)
	{
		fox_sprite(vars, "imgs/idle_fox_", 1);
	}
	else if (vars->utils.moving == 0 && vars->rev == 1 && vars->won == 0)
	{
		fox_sprite(vars, "imgs/idle_rev_fox_", 1);
	}
	else if (vars->won == 1)
	{
		fox_sprite(vars, "imgs/sleepy_fox_", 1);
	}
}

void	img_loading(t_vars *vars)
{
	vars->background.img = mlx_png_file_to_image(vars->mlx, "imgs/background.png", &vars->background.line_length, &vars->background.endian);
	vars->wall.img = mlx_png_file_to_image(vars->mlx, "imgs/tree.png", &vars->wall.line_length, &vars->wall.endian);
	vars->player.img.img = mlx_png_file_to_image(vars->mlx, "imgs/idle_fox_0.png", &vars->player.img.line_length, &vars->player.img.endian);
	vars->player.img_rev.img = mlx_png_file_to_image(vars->mlx, "imgs/idle_rev_fox_0.png", &vars->player.img_rev.line_length, &vars->player.img_rev.endian);
	vars->player.img_end.img = mlx_png_file_to_image(vars->mlx, "imgs/sleepy_fox_0.png", &vars->player.img_end.line_length, &vars->player.img_end.endian);
	vars->collectible.img = mlx_png_file_to_image(vars->mlx, "imgs/rasp2.png", &vars->collectible.line_length, &vars->collectible.endian);
	vars->exit.img = mlx_png_file_to_image(vars->mlx, "imgs/cave.png", &vars->exit.line_length, &vars->exit.endian);
	if (vars->background.img == NULL || vars->wall.img == NULL || /*vars->player.img.img == NULL || */vars->collectible.img == NULL || vars->exit.img == NULL)
		map_error("Image couldn't be loaded.\n");
	vars->background.addr = mlx_get_data_addr(vars->background.img, &vars->background.bits_per_pixel, &vars->background.line_length, &vars->background.endian);
	vars->wall.addr = mlx_get_data_addr(vars->wall.img, &vars->wall.bits_per_pixel, &vars->wall.line_length, &vars->wall.endian);
	vars->player.img.addr = mlx_get_data_addr(vars->player.img.img, &vars->player.img.bits_per_pixel, &vars->player.img.line_length, &vars->player.img.endian);
	vars->player.img_rev.addr = mlx_get_data_addr(vars->player.img_rev.img, &vars->player.img_rev.bits_per_pixel, &vars->player.img_rev.line_length, &vars->player.img_rev.endian);
	vars->player.img_end.addr = mlx_get_data_addr(vars->player.img_end.img, &vars->player.img_end.bits_per_pixel, &vars->player.img_end.line_length, &vars->player.img_end.endian);
	vars->collectible.addr = mlx_get_data_addr(vars->collectible.img, &vars->collectible.bits_per_pixel, &vars->collectible.line_length, &vars->collectible.endian);
	vars->exit.addr = mlx_get_data_addr(vars->exit.img, &vars->exit.bits_per_pixel, &vars->exit.line_length, &vars->exit.endian);
}

void	drawing_updated(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map.map_y)
	{
		j = 0;
		while (j < vars->map.map_x)
		{
			if (vars->map_array[i][j] != '0' && vars->map_array[i][j] != '1' && vars->map_array[i][j] != 'C' && vars->map_array[i][j] != 'E' && vars->map_array[i][j] != 'P')
				map_error("Unknown character encountered.\n");
			if (vars->map_array[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->wall.img, j * SIZE, i * SIZE);
			if (vars->map_array[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->collectible.img, j * SIZE + 10, i * SIZE + 12);
			if (vars->map_array[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->exit.img, j * SIZE - 15, i * SIZE - 7);
			if (vars->map_array[i][j] == 'P')
			{
				if (vars->player.pos_x == -1 && vars->player.pos_y == -1)
				{
					vars->player.pos_x = j * SIZE;
					vars->player.pos_y = i * SIZE;
				}
			}
			j ++;
		}
		i ++;
	}
}

void	draw_background(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map.res_y)
	{
		j = 0;
		while (j < vars->map.res_x)
		{
			mlx_put_image_to_window(vars->mlx, vars->wdw, vars->background.img, j, i);
			j += SIZE;
		}
		i += SIZE;
	}
}

void	game_data(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->wdw, vars->collectible.img, 10, vars->map.res_y + 10);
	mlx_string_put(vars->mlx, vars->wdw, 50, vars->map.res_y + 30, WHITE, "collected:");
	mlx_string_put(vars->mlx, vars->wdw, 125, vars->map.res_y + 30, WHITE, ft_itoa(vars->collected));
	mlx_string_put(vars->mlx, vars->wdw, vars->map.res_x - 160, vars->map.res_y + 30, WHITE, "number of moves:");
	mlx_string_put(vars->mlx, vars->wdw, vars->map.res_x - 40, vars->map.res_y + 30, WHITE, ft_itoa(vars->moves));
	if (vars->collected < vars->to_collect)
	{
		if (vars->pos_exit)
			mlx_string_put(vars->mlx, vars->wdw, vars->map.res_x / 2 - 150, vars->map.res_y + 30, WHITE, "Careful! There are still fruits to collect!");
		else
			mlx_string_put(vars->mlx, vars->wdw, vars->map.res_x / 2 - 150, vars->map.res_y + 30, WHITE, "Hurry! You need to grab all the fruits!");
	}
	if (vars->collected == vars->to_collect)
	{
		if (vars->won)
			mlx_string_put(vars->mlx, vars->wdw, vars->map.res_x / 2 - 150, vars->map.res_y + 30, WHITE, "Congratulations! You won!");
		else
			mlx_string_put(vars->mlx, vars->wdw, vars->map.res_x / 2 - 150, vars->map.res_y + 30, WHITE, "You got all the fruits, time to go home!");
	}
}

int	render(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->wdw);
	ft_printf("\033[K\rNumber of moves: %d | Number of fruits eaten: %d", vars->moves, vars->collected);
	draw_background(vars);
	drawing_updated(vars);
	draw_player(vars);
	game_data(vars);
	return (0);
}

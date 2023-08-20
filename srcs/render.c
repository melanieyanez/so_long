/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:18:39 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/20 23:00:51 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_player(t_vars *vars)
{
	if (vars->rev == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->wdw, vars->player.img.img, vars->player.pos_x, vars->player.pos_y);
	}
	else if (vars->rev == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->wdw, vars->player.img_rev.img, vars->player.pos_x, vars->player.pos_y);
	}
}

void	img_loading(t_vars *vars)
{
	vars->background.img = mlx_png_file_to_image(vars->mlx, "imgs/background2.png", &vars->background.line_length, &vars->background.endian);
	vars->wall.img = mlx_png_file_to_image(vars->mlx, "imgs/tree-variations2.png", &vars->wall.line_length, &vars->wall.endian);
	vars->player.img.img = mlx_png_file_to_image(vars->mlx, "imgs/fox.png", &vars->player.img.line_length, &vars->player.img.endian);
	vars->player.img_rev.img = mlx_png_file_to_image(vars->mlx, "imgs/fox_rev.png", &vars->player.img_rev.line_length, &vars->player.img_rev.endian);
	vars->collectible.img = mlx_png_file_to_image(vars->mlx, "imgs/rasp2.png", &vars->collectible.line_length, &vars->collectible.endian);
	vars->exit.img = mlx_png_file_to_image(vars->mlx, "imgs/waterfall.png", &vars->exit.line_length, &vars->exit.endian);
	if (vars->background.img == NULL || vars->wall.img == NULL || vars->player.img.img == NULL || vars->collectible.img == NULL || vars->exit.img == NULL)
	{
		printf("Error!\nImage couldn't be loaded.\n");
		exit (1);
	}
	vars->background.addr = mlx_get_data_addr(vars->background.img, &vars->background.bits_per_pixel, &vars->background.line_length, &vars->background.endian);
	vars->wall.addr = mlx_get_data_addr(vars->wall.img, &vars->wall.bits_per_pixel, &vars->wall.line_length, &vars->wall.endian);
	vars->player.img_rev.addr = mlx_get_data_addr(vars->player.img_rev.img, &vars->player.img_rev.bits_per_pixel, &vars->player.img_rev.line_length, &vars->player.img_rev.endian);
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
			{
				ft_printf("Error!\nUnknown character encountered.\n");
				exit(1);
			}
			if (vars->map_array[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->wall.img, j * SIZE, i * SIZE);
			if (vars->map_array[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->collectible.img, j * SIZE + 10, i * SIZE + 12);
			if (vars->map_array[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->exit.img, j * SIZE, i * SIZE);
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

// ajouter une condition de taille minimum pour afficher

void	game_data(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->wdw, vars->collectible.img, 10, vars->map.res_y + 10);
	mlx_string_put(vars->mlx, vars->wdw, 50, vars->map.res_y + 30, WHITE, "collected:");
	mlx_string_put(vars->mlx, vars->wdw, 125, vars->map.res_y + 30, WHITE, ft_itoa(vars->collected));
	mlx_string_put(vars->mlx, vars->wdw, vars->map.res_x - 150, vars->map.res_y + 30, WHITE, "number of moves:");
	mlx_string_put(vars->mlx, vars->wdw, vars->map.res_x - 30, vars->map.res_y + 30, WHITE, ft_itoa(vars->moves));
	if (vars->collected < vars->to_collect)
		mlx_string_put(vars->mlx, vars->wdw, vars->map.res_x / 2 - 150, vars->map.res_y + 30, WHITE, "Hurry! You need to grab all the fruits!");
	else if (vars->collected == vars->to_collect)
		mlx_string_put(vars->mlx, vars->wdw, vars->map.res_x / 2 - 150, vars->map.res_y + 30, WHITE, "You got all the fruits, go rest at the waterfall!");
}

int	render(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->wdw);
	draw_background(vars);
	drawing_updated(vars);
	draw_player(vars);
	game_data(vars);
	return (0);
}

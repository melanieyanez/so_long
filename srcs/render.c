/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:18:39 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/20 13:13:38 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_player(t_vars *vars, int i, int j)
{
	if (vars->player.pos_x == -1 && vars->player.pos_y == -1)
	{
		vars->player.pos_x = j * SIZE;
		vars->player.pos_y = i * SIZE;
	}
	mlx_put_image_to_window(vars->mlx, vars->wdw, vars->background.img, j * SIZE, i * SIZE);
	if (vars->rev == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->wdw, vars->player.img.img, vars->player.pos_x, vars->player.pos_y);
	}
	if (vars->rev == 1)
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
	vars->collectible.img = mlx_png_file_to_image(vars->mlx, "imgs/rasp.png", &vars->collectible.line_length, &vars->collectible.endian);
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, "imgs/exit.xpm", &vars->exit.line_length, &vars->exit.endian);
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
			if (vars->map_array[i][j] == '0')
			{
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->background.img, j * SIZE, i * SIZE);
			}
			if (vars->map_array[i][j] == '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->background.img, j * SIZE, i * SIZE);
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->wall.img, j * SIZE, i * SIZE);
			}
			if (vars->map_array[i][j] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->background.img, j * SIZE, i * SIZE);
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->collectible.img, j * SIZE, i * SIZE);
			}
			if (vars->map_array[i][j] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->background.img, j * SIZE, i * SIZE);
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->exit.img, j * SIZE, i * SIZE);
			}
			if (vars->map_array[i][j] == 'P')
			{
				draw_player(vars, i, j);
			}
			j ++;
		}
		i ++;
	}
}

void	draw_wall(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map.map_y)
	{
		j = 0;
		while (j < vars->map.map_x)
		{
			if (vars->map_array[i][j] == '1')
			{
				//mlx_put_image_to_window(vars->mlx, vars->wdw, vars->background.img, j * SIZE, i * SIZE);
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->wall.img, j * SIZE, i * SIZE);
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
	while (i < vars->map.map_y)
	{
		j = 0;
		while (j < vars->map.map_x)
		{
			mlx_put_image_to_window(vars->mlx, vars->wdw, vars->background.img, j * SIZE, i * SIZE);
			j ++;
		}
		i ++;
	}
}

void	game_data(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->wdw, vars->collectible.img,  vars->map.map_x - 20, vars->map.map_y * SIZE + 10);
	mlx_string_put(vars->mlx, vars->wdw, vars->map.map_x + 25, vars->map.map_y * SIZE + 30, 0xFF0000, "collected :");
	mlx_string_put(vars->mlx, vars->wdw, vars->map.map_x + 140, vars->map.map_y * SIZE + 30, 0xFF0000, ft_itoa(vars->collected));
}

int	render(t_vars *vars)
{
	//draw_background(vars); // doit dessiner le background partout
	//draw_wall(vars);
	drawing_updated(vars);
	//draw_player(vars); // doit dessiner le player en fct de pos.x et pos.y
	game_data(vars);
	return (0);
}

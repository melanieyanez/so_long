/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:18:39 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/16 12:18:51 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_loading(t_vars *vars)
{
	vars->background.img = mlx_png_file_to_image(vars->mlx, "imgs/background.png", &vars->background.line_length, &vars->background.endian);
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, "imgs/wall.xpm", &vars->wall.line_length, &vars->wall.endian);
	vars->player.img = mlx_xpm_file_to_image(vars->mlx, "imgs/player.xpm", &vars->player.line_length, &vars->player.endian);
	vars->collectible.img = mlx_xpm_file_to_image(vars->mlx, "imgs/collect.xpm", &vars->collectible.line_length, &vars->collectible.endian);
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, "imgs/exit.xpm", &vars->exit.line_length, &vars->exit.endian);
	if (vars->background.img == NULL || vars->wall.img == NULL || vars->player.img == NULL || vars->collectible.img == NULL || vars->exit.img == NULL)
	{
		printf("Error loading image\n");
		exit (1);
	}
	vars->background.addr = mlx_get_data_addr(vars->background.img, &vars->background.bits_per_pixel, &vars->background.line_length, &vars->background.endian);
	vars->wall.addr = mlx_get_data_addr(vars->wall.img, &vars->wall.bits_per_pixel, &vars->wall.line_length, &vars->wall.endian);
	vars->player.addr = mlx_get_data_addr(vars->player.img, &vars->player.bits_per_pixel, &vars->player.line_length, &vars->player.endian);
	vars->collectible.addr = mlx_get_data_addr(vars->collectible.img, &vars->collectible.bits_per_pixel, &vars->collectible.line_length, &vars->collectible.endian);
	vars->exit.addr = mlx_get_data_addr(vars->exit.img, &vars->exit.bits_per_pixel, &vars->exit.line_length, &vars->exit.endian);
}

void	drawing_updated(t_vars *vars)
{
	int	i;
	int	j;

	img_loading(vars);
	i = 0;
	while (vars->map_array[i])
	{
		j = 0;
		while (vars->map_array[i][j])
		{
			if (vars->map_array[i][j] == '0')
			{
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->background.img, j * SIZE, i * SIZE);
			}
			else if (vars->map_array[i][j] == '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->background.img, j * SIZE, i * SIZE);
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->wall.img, j * SIZE, i * SIZE);
			}
			else if (vars->map_array[i][j] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->player.img, j * SIZE, i * SIZE);
			}
			else if (vars->map_array[i][j] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->background.img, j * SIZE, i * SIZE);
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->collectible.img, j * SIZE, i * SIZE);
			}
			else if (vars->map_array[i][j] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->exit.img, j * SIZE, i * SIZE);
			}
			j ++;
		}
		i ++;
	}
}

void	draw_background(t_vars *vars)
{
	int	size;
	int	rep_x;
	int	rep_y;
	int	i;
	int	j;

	vars->background.img = mlx_png_file_to_image(vars->mlx, "imgs/background.png", &vars->background.line_length, &vars->background.endian);
	if (vars->background.img == NULL)
	{
		printf("Error loading background image\n");
		return ;
	}
	vars->background.addr = mlx_get_data_addr(vars->background.img, &vars->background.bits_per_pixel, &vars->background.line_length, &vars->background.endian);
	size = vars->background.line_length / (vars->background.bits_per_pixel / 8);
	rep_x = (WIDTH + size - 1) / size;
	rep_y = (HEIGHT + size - 1) / size;
	i = 0;
	while (i < rep_x)
	{
		j = 0;
		while (j < rep_y)
		{
			mlx_put_image_to_window(vars->mlx, vars->wdw, vars->background.img, i * size, j * size);
			j ++;
		}
		i ++;
	}
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	drawing(t_vars *vars)
{
	int			x;
	int			y;

	x = vars->square.start_x;
	while (x < vars->square.size + vars->square.start_x)
	{
		y = vars->square.start_y;
		while (y < vars->square.size + vars->square.start_y)
		{
			my_mlx_pixel_put((&(vars->img)), x, y, GREEN);
			y ++;
		}
		x ++;
	}
}

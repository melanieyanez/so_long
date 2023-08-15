/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:18:39 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/15 18:30:27 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	drawing_updated(t_vars *vars, char *line)
{
	int	i;
	int	j;

	vars->tile_size_x = WIDTH / vars->map.map_x;
	vars->tile_size_y = HEIGHT / vars->map.map_y;
	vars->background.img = mlx_png_file_to_image(vars->mlx, "imgs/background.png", &vars->background.line_length, &vars->background.endian);
	vars->test.img = mlx_xpm_file_to_image(vars->mlx, "imgs/floor.xpm", &vars->test.line_length, &vars->test.endian);
	if (vars->background.img == NULL)
	{
		printf("Error loading background image\n");
		return ;
	}
	vars->background.addr = mlx_get_data_addr(vars->background.img, &vars->background.bits_per_pixel, &vars->background.line_length, &vars->background.endian);
	vars->test.addr = mlx_get_data_addr(vars->test.img, &vars->test.bits_per_pixel, &vars->test.line_length, &vars->test.endian);
	i = 0;
	while (i < vars->map.map_x)
	{
		j = 0;
		while (j < vars->map.map_y)
		{
			if (line[i] == '0')
			{
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->background.img, i * vars->tile_size_x, j * vars->tile_size_y);
			}
			else if (line[i] == '1')
				mlx_put_image_to_window(vars->mlx, vars->wdw, vars->test.img, i * vars->tile_size_x, j * vars->tile_size_y);			
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

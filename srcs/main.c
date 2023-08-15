/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:52:36 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/11 17:58:16 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Trouver un moyen quand on quitte la fenêtre pour que ca segfault pas */

/* gcc -Lmlx -lmlx -framework OpenGL -framework AppKit main.c -o so_long */

#include "../includes/so_long.h"


void initialization(t_vars *vars)
{
	vars->square.start_x = 5;
	vars->square.start_y = 5;
	vars->square.size = 50;
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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

int close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->wdw);
	printf("You successfully fleed from the dungeon.\n");
	exit(0);
	return(0);
}

int mouse_actions(int key, t_vars *vars)
{
	if (key == 6)
		printf("Hello!\n");
	else if (key == 7)
		printf("Goodbye!\n");
	return(0);
}

int	key_actions(int key, t_vars *vars)
{
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->wdw);
		printf("You successfully fleed from the dungeon.\n");
		exit(0);
	}
	else if (key == KEY_LEFT)
	{
		vars->square.start_x -= 10;
	}
	else if (key == KEY_RIGHT)
	{
		vars->square.start_x += 10;
	}
	else if (key == KEY_UP)
	{
		vars->square.start_y -= 10;
	}
	else if (key == KEY_DOWN)
	{
		vars->square.start_y += 10;
	}
	mlx_clear_window(vars->mlx, vars->wdw);
	drawing(vars);
	mlx_put_image_to_window(vars->mlx, vars->wdw, vars->img.img, 0, 0);
	return(0);
}

int	main(void)
{
	t_vars vars;

	initialization(&vars);
	vars.mlx = mlx_init();
	vars.wdw = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Moving Square");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	drawing(&vars);
	mlx_put_image_to_window(vars.mlx, vars.wdw, vars.img.img, 0, 0);
	mlx_hook(vars.wdw, 2, 0, key_actions, &vars);
	mlx_hook(vars.wdw, 17, 0, close_window, &vars);
	mlx_loop(vars.mlx);
	return(0);
}
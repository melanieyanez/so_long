/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:18:31 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/16 22:33:07 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->wdw);
	printf("You successfully fleed from the dungeon.\n");
	exit(0);
	return (0);
}

int	mouse_actions(int key, t_vars *vars)
{
	if (key == 6)
		printf("Hello!\n");
	else if (key == 7)
		printf("Goodbye!\n");
	return (0);
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
		vars->player.pos_x += SIZE;
		printf("pos x %d\n", vars->player.pos_x);
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
	//draw_background(vars);
	drawing_updated(vars);
	mlx_put_image_to_window(vars->mlx, vars->wdw, vars->img.img, 0, 0);
	return (0);
}

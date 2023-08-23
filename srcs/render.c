/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:18:39 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/23 11:01:42 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	line_interpreter(t_vars *vars, int *i, int *j)
{
	if (vars->map_array[*i][*j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->wdw, \
			vars->wall.img, *j * SIZE, *i * SIZE);
	if (vars->map_array[*i][*j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->wdw, \
			vars->collectible.img, *j * SIZE + 10, *i * SIZE + 12);
	if (vars->map_array[*i][*j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->wdw, \
			vars->exit.img, *j * SIZE - 15, *i * SIZE - 7);
	if (vars->map_array[*i][*j] == 'P')
	{
		if (vars->player.pos_x == -1 && vars->player.pos_y == -1)
		{
			vars->player.pos_x = *j * SIZE;
			vars->player.pos_y = *i * SIZE;
		}
	}
}

void	draw_objects(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map.map_y)
	{
		j = 0;
		while (j < vars->map.map_x)
		{
			line_interpreter(vars, &i, &j);
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
			mlx_put_image_to_window(vars->mlx, vars->wdw, \
				vars->background.img, j, i);
			j += SIZE;
		}
		i += SIZE;
	}
}

void	game_data(t_vars *vars)
{
	if (vars->map.map_x >= 7)
	{
		mlx_put_image_to_window(vars->mlx, vars->wdw, \
			vars->collectible.img, 10, vars->map.res_y + 10);
		mlx_string_put(vars->mlx, vars->wdw, \
			50, vars->map.res_y + 30, WHITE, "collected:");
		mlx_string_put(vars->mlx, vars->wdw, 125, \
			vars->map.res_y + 30, WHITE, ft_itoa(vars->utils.collected));
		mlx_string_put(vars->mlx, vars->wdw, \
			vars->map.res_x - 160, vars->map.res_y + 30, WHITE, \
			"number of moves:");
		mlx_string_put(vars->mlx, vars->wdw, vars->map.res_x - 40, \
			vars->map.res_y + 30, WHITE, ft_itoa(vars->utils.moves));
	}
}

void	game_sentences(t_vars *vars)
{
	if (vars->map.map_x >= 13)
	{
		if (vars->utils.collected < vars->utils.to_collect)
		{
			if (vars->utils.pos_exit)
				mlx_string_put(vars->mlx, vars->wdw, vars->map.res_x / 2 - 160, \
				vars->map.res_y + 30, WHITE, "Careful! There are still \
					fruits to collect!");
			else
				mlx_string_put(vars->mlx, vars->wdw, vars->map.res_x / 2 - 140, \
					vars->map.res_y + 30, WHITE, "Hurry! You need to grab \
						all the fruits!");
		}
		if (vars->utils.collected == vars->utils.to_collect)
		{
			if (vars->utils.won)
				mlx_string_put(vars->mlx, vars->wdw, vars->map.res_x / 2 - 90, \
					vars->map.res_y + 30, WHITE, "Congratulations! You won!");
			else
				mlx_string_put(vars->mlx, vars->wdw, vars->map.res_x / 2 - 150, \
					vars->map.res_y + 30, WHITE, "You got all the fruits,\
						time to go home!");
		}
	}
}

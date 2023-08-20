/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:18:31 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/20 13:38:07 by melanieyane      ###   ########.fr       */
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

void	player_pos(t_vars *vars, int pot_x, int pot_y)
{
	if (pot_x <= vars->map.res_x - SIZE && pot_x >= 0 && pot_y <= vars->map.res_y - SIZE && pot_y >= 0)
	{
		vars->moves ++;
		if (vars->map_array[(pot_y) / SIZE][(pot_x) / SIZE] == '0' || vars->map_array[(pot_y) / SIZE][(pot_x) / SIZE] == 'P')
		{
			vars->player.pos_x = pot_x;
			vars->player.pos_y = pot_y;
		}
		else if (vars->map_array[(pot_y) / SIZE][(pot_x) / SIZE] == 'C')
		{
			vars->collected ++;
			vars->map_array[(pot_y) / SIZE][(pot_x) / SIZE] = '0';
			vars->player.pos_x = pot_x;
			vars->player.pos_y = pot_y;
		}
		else if (vars->map_array[(pot_y) / SIZE][(pot_x) / SIZE] == 'E')
		{
			vars->player.pos_x = pot_x;
			vars->player.pos_y = pot_y;
		}
	}
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
		vars->rev = 1;
		player_pos(vars, vars->player.pos_x - SIZE, vars->player.pos_y);
		//if ((vars->player.pos_x - SIZE) >= 0)
		//	vars->player.pos_x -= SIZE;
	}
	else if (key == KEY_RIGHT)
	{
		vars->rev = 0;
		player_pos(vars, vars->player.pos_x + SIZE, vars->player.pos_y);
		//if ((vars->player.pos_x / SIZE) < vars->map.map_x - 1)
		//	vars->player.pos_x += SIZE;
	}
	else if (key == KEY_UP)
	{
		player_pos(vars, vars->player.pos_x, vars->player.pos_y - SIZE);
		//if ((vars->player.pos_y - SIZE) >= 0)
		//{
		//	if ((vars->player.pos_y >= SIZE) && (vars->map_array[vars->player.pos_x / SIZE][vars->player.pos_y - SIZE / SIZE - 1] != '1'))
		//		vars->player.pos_y -= SIZE;
		//}
	}
	else if (key == KEY_DOWN)
	{
		player_pos(vars, vars->player.pos_x, vars->player.pos_y + SIZE);
		//if ((vars->player.pos_y / SIZE) < vars->map.map_y - 1)
		//	vars->player.pos_y += SIZE;
	}
	return (0);
}

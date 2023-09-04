/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:18:31 by melanieyane       #+#    #+#             */
/*   Updated: 2023/09/04 14:57:50 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*----------------------------------------------*/
/* Handles the player's movement and interactions with objects. */

void	player_pos(t_vars *vars, int pot_x, int pot_y)
{
	if (pot_x <= vars->map.res_x - SIZE && pot_x >= 0
		&& pot_y <= vars->map.res_y - SIZE && pot_y >= 0)
	{
		vars->utils.moves ++;
		if (vars->map_array[(vars->\
			player.pos_y) / SIZE][(vars->player.pos_x) / SIZE] == 'E')
			vars->utils.pos_exit = 1;
		if (vars->map_array[(pot_y) / SIZE][(pot_x) / SIZE] == '0'
			|| vars->map_array[(pot_y) / SIZE][(pot_x) / SIZE] == 'P')
		{
			vars->utils.pos_exit = 0;
			vars->player.pos_x = pot_x;
			vars->player.pos_y = pot_y;
		}
		player_pos_ext(vars, &pot_x, &pot_y);
	}
}

/*----------------------------------------------*/

void	player_pos_ext(t_vars *vars, int *pot_x, int *pot_y)
{
	if (vars->map_array[(*pot_y) / SIZE][(*pot_x) / SIZE] == 'C')
	{
		vars->utils.pos_exit = 0;
		vars->utils.collected ++;
		if (vars->utils.collected == vars->utils.to_collect)
			vars->utils.exit_unlocked = 1;
		vars->map_array[(*pot_y) / SIZE][(*pot_x) / SIZE] = '0';
		vars->player.pos_x = *pot_x;
		vars->player.pos_y = *pot_y;
	}
	else if (vars->map_array[(*pot_y) / SIZE][(*pot_x) / SIZE] == 'E')
	{
		vars->utils.pos_exit = 1;
		if (vars->utils.exit_unlocked == 1)
		{
			ft_printf("\nCongratulations! You won!\n");
			vars->utils.won = 1;
		}
		vars->player.pos_x = *pot_x;
		vars->player.pos_y = *pot_y;
	}
}

/*----------------------------------------------*/
/*  Respond to key presses and releases 
	to control player movement and exit the game. */

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->wdw);
	if (vars->utils.won == 0)
		ft_printf("\nYou successfully fleed from the dungeon.\n");
	exit(0);
	return (0);
}

/*----------------------------------------------*/

int	key_press_actions(int key, t_vars *vars)
{
	vars->utils.moving = 1;
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->wdw);
		if (vars->utils.won == 0)
			ft_printf("\nYou successfully fleed from the dungeon.\n");
		exit(0);
	}
	else if (key == KEY_LEFT && vars->utils.won == 0)
	{
		vars->utils.rev = 1;
		player_pos(vars, vars->player.pos_x - SIZE, vars->player.pos_y);
	}
	else if (key == KEY_RIGHT && vars->utils.won == 0)
	{
		vars->utils.rev = 0;
		player_pos(vars, vars->player.pos_x + SIZE, vars->player.pos_y);
	}
	else if (key == KEY_UP && vars->utils.won == 0)
		player_pos(vars, vars->player.pos_x, vars->player.pos_y - SIZE);
	else if (key == KEY_DOWN && vars->utils.won == 0)
		player_pos(vars, vars->player.pos_x, vars->player.pos_y + SIZE);
	else
		vars->utils.moving = 0;
	return (0);
}

/*----------------------------------------------*/

int	key_release_actions(int key, t_vars *vars)
{
	(void)key;
	vars->utils.moving = 0;
	return (0);
}

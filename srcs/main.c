/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:52:36 by melanieyane       #+#    #+#             */
/*   Updated: 2023/09/04 14:06:13 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*----------------------------------------------*/
/* The main rendering function that redraws the game scene. */

int	render(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->wdw);
	if (vars->utils.won == 0)
		ft_printf("\033[K\rNumber of moves: %d | Number of fruits eaten: %d", \
			vars->utils.moves, vars->utils.collected);
	draw_background(vars);
	draw_objects(vars);
	draw_player(vars);
	game_data(vars);
	game_sentences(vars);
	return (0);
}

/*----------------------------------------------*/

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		map_error("Please enter only one map path.\n");
	initialization(&vars, argv[1]);
	array_filler(&vars);
	vars.mlx = mlx_init();
	vars.wdw = mlx_new_window(vars.mlx, vars.map.map_x * SIZE, \
		vars.map.map_y * SIZE + SIZE, "Forest Quest");
	mlx_hook(vars.wdw, 2, 0, key_press_actions, &vars);
	mlx_hook(vars.wdw, 3, 0, key_release_actions, &vars);
	mlx_hook(vars.wdw, 17, 0, close_window, &vars);
	img_loading(&vars);
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_loop(vars.mlx);
	free_array(&vars);
	return (0);
}

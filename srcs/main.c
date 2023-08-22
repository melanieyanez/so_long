/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:52:36 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/22 17:20:24 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	vars.img.img = mlx_new_image(vars.mlx, vars.map.map_x * SIZE, \
		vars.map.map_y * SIZE);
	vars.img.addr = mlx_get_data_addr(vars.img.img, \
		&vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	mlx_hook(vars.wdw, 2, 0, key_press_actions, &vars);
	mlx_hook(vars.wdw, 3, 0, key_release_actions, &vars);
	mlx_hook(vars.wdw, 17, 0, close_window, &vars);
	img_loading(&vars);
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_loop(vars.mlx);
	free_array(&vars);
	mlx_destroy_image(vars.mlx, vars.img.img);
	return (0);
}

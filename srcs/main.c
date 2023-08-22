/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:52:36 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/22 11:31:49 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Réduire les lignes trop longues */
/* Ajouter la condition while (!won) */
/* Affichage de la victoire dans le shell ? */
/* Ajouter animation victoire */
/* Free array et line */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		map_error("Please enter only one map path.\n");
	initialization(&vars, argv[1]);
	extension_checker(&vars);
	map_parser(&vars);
	vars.mlx = mlx_init();
	vars.wdw = mlx_new_window(vars.mlx, vars.map.map_x * SIZE, vars.map.map_y * SIZE + SIZE, "Forest Quest");
	vars.img.img = mlx_new_image(vars.mlx, vars.map.map_x * SIZE, vars.map.map_y * SIZE);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	mlx_hook(vars.wdw, 2, 0, key_press_actions, &vars);
	mlx_hook(vars.wdw, 3, 0, key_release_actions, &vars);
	mlx_hook(vars.wdw, 17, 0, close_window, &vars);
	img_loading(&vars);
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_loop(vars.mlx);
	//mlx_destroy_image(vars.mlx, vars.player.img.img);
	//vars.player.img.img = NULL; 
	//mlx_destroy_image(vars.mlx, vars.player.img_rev.img);
	//vars.player.img_rev.img = NULL; 
	mlx_destroy_image(vars.mlx, vars.img.img);
	return (0);
}

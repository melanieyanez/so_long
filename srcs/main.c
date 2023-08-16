/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:52:36 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/16 10:51:04 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* gcc -Lmlx -lmlx -framework OpenGL -framework AppKit main.c -o so_long */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		exit (1);
	initialization(&vars, argv[1]);
	map_parser(&vars);
	vars.mlx = mlx_init();
	vars.wdw = mlx_new_window(vars.mlx, vars.map.map_x * SIZE, vars.map.map_y * SIZE, "Jungle Quest");
	vars.img.img = mlx_new_image(vars.mlx, vars.map.map_x * SIZE, vars.map.map_y * SIZE);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	drawing_updated(&vars);
	mlx_hook(vars.wdw, 2, 0, key_actions, &vars);
	mlx_hook(vars.wdw, 17, 0, close_window, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_image(vars.mlx, vars.img.img);
	return (0);
}

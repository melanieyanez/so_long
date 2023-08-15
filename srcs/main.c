/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:52:36 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/15 18:14:44 by melanieyane      ###   ########.fr       */
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
	vars.mlx = mlx_init();
	vars.wdw = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Moving Square");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	//vars.map.path = "maps/empty.ber";
	map_parser(&vars);
	//draw_background(&vars);
	//drawing(&vars);
	//mlx_put_image_to_window(vars.mlx, vars.wdw, vars.img.img, 0, 0);
	mlx_hook(vars.wdw, 2, 0, key_actions, &vars);
	mlx_hook(vars.wdw, 17, 0, close_window, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_image(vars.mlx, vars.img.img);
	return (0);
}

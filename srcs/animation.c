/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 06:49:45 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/22 14:36:41 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_player(t_vars *vars)
{
	if (vars->utils.moving == 1 && vars->utils.rev == 0 && vars->utils.won == 0)
	{
		fox_sprite(vars, "imgs/moving_fox_", 8);
	}
	else if (vars->utils.moving == 1 && vars->utils.rev == 1 \
		&& vars->utils.won == 0)
	{
		fox_sprite(vars, "imgs/moving_rev_fox_", 8);
	}
	else if (vars->utils.moving == 0 && vars->utils.rev == 0 \
		&& vars->utils.won == 0)
	{
		fox_sprite(vars, "imgs/idle_fox_", 1);
	}
	else if (vars->utils.moving == 0 && vars->utils.rev == 1 \
		&& vars->utils.won == 0)
	{
		fox_sprite(vars, "imgs/idle_rev_fox_", 1);
	}
	else if (vars->utils.won == 1)
	{
		fox_sprite(vars, "imgs/sleepy_fox_", 1);
	}
}

void	fox_sprite(t_vars *vars, char *foxtype, int num_frames)
{
	int		i;
	char	*filename;

	i = 0;
	while (i < num_frames)
	{
		filename = ft_strjoin(foxtype, ft_itoa(i));
		filename = ft_strjoin(filename, ".png");
		vars->player.sprite_frames[i] = mlx_png_file_to_image(vars->mlx, \
			filename, &vars->background.line_length, &vars->background.endian);
		if (vars->player.sprite_frames[i] == NULL)
			map_error("Image couldn't be loaded.\n");
		free(filename);
		i ++;
	}
	mlx_put_image_to_window(vars->mlx, vars->wdw, vars->player.sprite_frames \
		[vars->player.current_frame], vars->player.pos_x, vars->player.pos_y);
	vars->player.current_frame = (vars->player.current_frame + 1) % num_frames;
}

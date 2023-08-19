/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:00:40 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/19 17:39:17 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/so_long.h>

void	initialization(t_vars *vars, char *file)
{
	vars->map.path = ft_strdup(file);
	map_size(vars);
	vars->map.res_x = vars->map.map_x * SIZE;
	vars->map.res_y = vars->map.map_y * SIZE;
	vars->map_array = malloc(sizeof(char *) * vars->map.map_y);
	vars->player.pos_x = -1;
	vars->player.pos_y = -1;
	vars->rev = 0;
	vars->collected = 0;
	vars->moves = 0;
}

void	map_size(t_vars *vars)
{
	int		fd;
	char	*line;

	fd = open(vars->map.path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening map\n");
		exit (1);
	}
	vars->map.map_x = 0;
	vars->map.map_y = 0;
	line = get_next_line(fd);
	while (line)
	{
		vars->map.map_y++;
		vars->map.map_x = ft_strlen(line);
		line = get_next_line(fd);
	}
	close(fd);
}

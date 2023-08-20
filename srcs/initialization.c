/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:00:40 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/20 16:04:06 by melanieyane      ###   ########.fr       */
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
	vars->to_collect = 0;
	vars->exit_unlocked = 0;
	vars->won = 0;
	vars->exit_found = 0;
	vars->start_found = 0;
}

int	linelen(char *str)
{
	int	size;

	while (str[size] && str[size] != '\n')
		size++;
	return (size);
}

void	map_size(t_vars *vars) //devrait etre le map parser
{
	int		fd;
	char	*line;

	fd = open(vars->map.path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error!\nError opening map.\n");
		exit (1);
	}
	vars->map.map_x = 0;
	vars->map.map_y = 0;
	line = get_next_line(fd);
	while (line)
	{
		vars->map.map_y++;
		if (vars->map.map_y == 1)
			vars->map.map_x = linelen(line);
		if (linelen(line) != vars->map.map_x)
		{
			ft_printf("Error!\nThe map is not rectangular.\n");
			exit(1);
		}
		line = get_next_line(fd);
	}
	close(fd);
}

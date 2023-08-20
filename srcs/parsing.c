/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:52:45 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/20 16:06:00 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
void	line_interpreter(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		draw_background();
		if (line[i] == '1')
			draw_wall();
		else if (line[i] == 'C')
			draw_collectible();
		else if (line[i] == 'P')
			draw_player();
		else if (line[i] == 'E')
			draw_exit();
	}
}
*/

void	map_counter(t_vars *vars, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			vars->start_found ++;
		else if (line[i] == 'E')
			vars->exit_found ++;
		else if (line[i] == 'C')
			vars->to_collect ++;
		i ++;
	}
}

// ajouter le reste des erreurs

void	map_parser(t_vars *vars) // devrait etre le array filler
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(vars->map.path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map_counter(vars, line);
		vars->map_array[i] = ft_strdup(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	if (vars->start_found > 1 || vars->exit_found > 1)
	{
		ft_printf("Error!\nMultiple start or exit found.\n");
		exit (1);
	}
}

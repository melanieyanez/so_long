/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:52:45 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/21 21:20:09 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Modifier le nom du map parser en array filler */
/* et ajouter la fonction de initialization.c */
/* Ajouter la condition while (!won) */

#include "../includes/so_long.h"

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

void	map_parser(t_vars *vars)
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
	map_checker(vars);
	wall_checker(vars);
	path_checker(vars);
}

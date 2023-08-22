/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:52:45 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/22 14:06:10 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_counter(t_vars *vars, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			vars->utils.start_found ++;
		else if (line[i] == 'E')
			vars->utils.exit_found ++;
		else if (line[i] == 'C')
			vars->utils.to_collect ++;
		i ++;
	}
}

void	array_filler(t_vars *vars)
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

void	map_parser(t_vars *vars)
{
	int		fd;
	char	*line;

	fd = open(vars->map.path, O_RDONLY);
	if (fd < 0)
		map_error("Error opening map.\n");
	vars->map.map_x = 0;
	vars->map.map_y = 0;
	line = get_next_line(fd);
	while (line)
	{
		vars->map.map_y++;
		if (vars->map.map_y == 1)
			vars->map.map_x = linelen(line);
		if (linelen(line) != vars->map.map_x)
			map_error("The map is not rectangular.\n");
		line = get_next_line(fd);
	}
	if (vars->map.map_x == 0)
		map_error("The map is empty.\n");
	close(fd);
}

int	linelen(char *str)
{
	int	size;

	while (str[size] && str[size] != '\n')
		size++;
	return (size);
}

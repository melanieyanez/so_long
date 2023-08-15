/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:52:45 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/15 18:14:06 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	line_interpreter(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			return ;
	}
}

void	map_parser(t_vars *vars)
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
		drawing_updated(vars, line);
		//line_interpreter(line);
		line = get_next_line(fd);
	}
	close(fd);
}

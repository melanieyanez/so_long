/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:00:40 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/22 11:59:25 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Faire la fonction initialization plus propre */
/* Modifier le nom de la fonction map size en map parser */
/* et la passer dans le fichier parsing.c */
/* Ajouter la condition while (!won) */

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
	vars->pos_exit = 0;
	vars->player.current_frame = 0;
	vars->utils.moving = 0;
}

int	linelen(char *str)
{
	int	size;

	while (str[size] && str[size] != '\n')
		size++;
	return (size);
}

void	map_size(t_vars *vars)
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

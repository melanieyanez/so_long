/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:00:37 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/22 23:54:15 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Créer la fonction path checker */
/* Ajouter si la tile a déjà été visitée mais comment ? */

#include "../includes/so_long.h"

void	map_error(char *error_message)
{
	ft_printf("Error!\n");
	ft_printf("%s", error_message);
	exit (1);
}

void	map_checker(t_vars *vars)
{
	if (vars->utils.start_found > 1)
		map_error("Multiple starts found.\n");
	else if (vars->utils.start_found < 1)
		map_error("No start position found.\n");
	else if (vars->utils.exit_found > 1)
		map_error("Multiple exits found.\n");
	else if (vars->utils.exit_found < 1)
		map_error("No exit found.\n");
	else if (vars->utils.to_collect < 1)
		map_error("No collectible found.\n");
}

void	wall_checker(t_vars *vars)
{	
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->map.map_x)
	{
		if (vars->map_array[0][i] != '1' ||
			vars->map_array[vars->map.map_y - 1][i] != '1')
			map_error("Map not enclosed into walls.\n");
		i ++;
	}
	while (j < vars->map.map_y)
	{
		if (vars->map_array[j][0] != '1' ||
			vars->map_array[j][vars->map.map_x - 1] != '1')
			map_error("Map not enclosed into walls.\n");
		j ++;
	}
}

/*
void	path_checker(t_vars *vars, int x, int y)
{
	if (vars->map_array[x][y] == '1' || x < 0 || y < 0
		|| x >= vars->map.map_x || y >= vars->map.map_y)
		return ;
	if (vars->map_array[x][y] == 'C')
		vars->utils.collect_access ++;
	else if (vars->map_array[x][y] == 'E')
		vars->utils.exit_access = 1;
	path_checker(vars, x - 1, y);
	path_checker(vars, x + 1, y);
	path_checker(vars, x, y - 1);
	path_checker(vars, x, y + 1);
}
*/

void	extension_checker(t_vars *vars)
{
	const char	*extension;

	extension = ".ber";
	if (ft_strlen(vars->map.path) >= ft_strlen(extension)
		&& ft_strncmp(vars->map.path + ft_strlen(vars->map.path) \
		- ft_strlen(extension), extension, ft_strlen(extension)) != 0)
		map_error("Invalid file extension.\n");
}

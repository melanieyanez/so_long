/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:00:37 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/25 19:38:19 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*----------------------------------------------*/
/* Prints error messages and exits the program. */

void	map_error(t_vars *vars, char *error_message)
{
	ft_printf("Error!\n");
	ft_printf("%s", error_message);
	if (vars->map_array && vars->visited)
		free_array(vars);
	exit (1);
}

/*----------------------------------------------*/
/* Checks if the map meets certain criteria. */

void	map_checker(t_vars *vars)
{
	if (vars->utils.start_found > 1)
		map_error(vars, "Multiple starts found.\n");
	else if (vars->utils.start_found < 1)
		map_error(vars, "No start position found.\n");
	else if (vars->utils.exit_found > 1)
		map_error(vars, "Multiple exits found.\n");
	else if (vars->utils.exit_found < 1)
		map_error(vars, "No exit found.\n");
	else if (vars->utils.to_collect < 1)
		map_error(vars, "No collectible found.\n");
}

/*----------------------------------------------*/
/* Checks if the map is enclosed by walls. */

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
			map_error(vars, "Map not enclosed into walls.\n");
		i ++;
	}
	while (j < vars->map.map_y)
	{
		if (vars->map_array[j][0] != '1' ||
			vars->map_array[j][vars->map.map_x - 1] != '1')
			map_error(vars, "Map not enclosed into walls.\n");
		j ++;
	}
}

/*----------------------------------------------*/
/* Checks if a valid path exists from the player's starting position
   to the exit while collecting collectibles. */

void	path_checker(t_vars *vars, int x, int y)
{
	if (x < 0 || y < 0
		|| y > vars->map.map_x - 1 || x > vars->map.map_y - 1)
		return ;
	if (vars->map_array[x][y] == '1' || vars->visited[x][y] == 1)
		return ;
	vars->visited[x][y] = 1;
	if (vars->map_array[x][y] == 'C')
		vars->utils.collect_access ++;
	else if (vars->map_array[x][y] == 'E')
		vars->utils.exit_access ++;
	path_checker(vars, x - 1, y);
	path_checker(vars, x + 1, y);
	path_checker(vars, x, y - 1);
	path_checker(vars, x, y + 1);
}

/*----------------------------------------------*/
/* Checks if the map file has the correct file extension. */

void	extension_checker(t_vars *vars)
{
	const char	*extension;

	extension = ".ber";
	if (ft_strlen(vars->map.path) >= ft_strlen(extension)
		&& ft_strncmp(vars->map.path + ft_strlen(vars->map.path) \
		- ft_strlen(extension), extension, ft_strlen(extension)) != 0)
		map_error(vars, "Invalid file extension.\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:26:30 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/31 19:54:01 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*----------------------------------------------*/
/* Frees memory used for storing the map and visited array. */

void	free_array(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map.map_y)
	{
		free(vars->visited[i]);
		vars->visited[i] = NULL;
		free(vars->map_array[i]);
		vars->map_array[i] = NULL;
		i ++;
	}
	free(vars->visited);
	vars->visited = NULL;
	free(vars->map_array);
	vars->map_array = NULL;
	free(vars->map.path);
	vars->map.path = NULL;
}

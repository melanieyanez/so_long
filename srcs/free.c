/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:26:30 by melanieyane       #+#    #+#             */
/*   Updated: 2023/08/25 19:23:57 by melanieyane      ###   ########.fr       */
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
		free(vars->map_array[i]);
		i ++;
	}
	free(vars->visited);
	free(vars->map_array);
}

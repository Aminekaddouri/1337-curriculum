/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_collectibles_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 03:26:14 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/11 01:36:33 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	count_collectibles(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->collectibles = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (map->map[i][j] == 'C')
				map->collectibles++;
			j++;
		}
		i++;
	}
}

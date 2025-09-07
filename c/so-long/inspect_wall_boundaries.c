/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_wall_boundaries.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 01:54:39 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/25 21:59:23 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_map_walls(t_map *map)
{
	ft_printf("%sError%s\n", RED, END);
	ft_printf("%sThe map is not surrounded by walls%s\n", LIGHT_YELLOW, END);
	free_map(map);
	exit(EXIT_FAILURE);
}

int	inspect_wall_boundaries(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->col = ft_strlen(map->map[0]);
	while (i < map->row)
	{
		j = 0;
		while (map->map[i][j] && j < map->col)
		{
			if (i == 0 || i == map->row - 1)
				if (map->map[i][j] != '1')
					return (1);
			if (j == 0 || j == map->col - 1)
				if (map->map[i][j] != '1')
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

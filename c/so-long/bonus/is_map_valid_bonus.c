/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:23:37 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/27 02:35:51 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->row || y >= map->col)
		return ;
	if (map->map[x][y] == COL || map->map[x][y] == EXIT
		|| map->map[x][y] == PLAYER || map->map[x][y] == EMPTY
		|| map->map[x][y] == ENEMY)
	{
		map->map[x][y] = 'X';
		flood_fill(map, x + 1, y);
		flood_fill(map, x - 1, y);
		flood_fill(map, x, y + 1);
		flood_fill(map, x, y - 1);
	}
}

static	int	check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (map->map[i][j] == COL || map->map[i][j] == EXIT
				|| map->map[i][j] == PLAYER)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_map_valid(t_map *map, char *file)
{
	int	result;
	int	result1;

	map->map[map->dx][map->dy] = '1';
	flood_fill(map, map->x, map->y);
	result = check(map);
	free_map(map);
	load_map(file, map);
	flood_fill(map, map->x, map->y);
	result1 = check(map);
	free_map(map);
	return (result && result1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_enemy_position_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 03:15:08 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/25 19:46:05 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	count_enemies(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->enemy_count = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (map->map[i][j] == 'Y')
				map->enemy_count++;
			j++;
		}
		i++;
	}
}

void	process_row_for_enemies(t_map *map, int i, int *enemy_index)
{
	int	j;

	j = 0;
	while (j < map->col)
	{
		if (map->map[i][j] == 'Y')
		{
			map->enemy_positions[*enemy_index] = malloc(sizeof(int) * 2);
			if (!map->enemy_positions[*enemy_index])
			{
				ft_printf("%s\n", MALLOC_ERROR);
				exit(EXIT_FAILURE);
			}
			map->enemy_positions[*enemy_index][0] = i;
			map->enemy_positions[*enemy_index][1] = j;
			map->enemy_direction[*enemy_index] = 'L';
			(*enemy_index)++;
		}
		j++;
	}
}

void	get_enemy_positions(t_map *map)
{
	int	i;
	int	enemy_index;

	enemy_index = 0;
	map->enemy_positions = malloc(sizeof(int *) * map->enemy_count);
	map->enemy_direction = malloc(sizeof(char) * map->enemy_count);
	if (!map->enemy_positions || !map->enemy_direction)
	{
		ft_printf("%s\n", MALLOC_ERROR);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < map->row)
	{
		process_row_for_enemies(map, i, &enemy_index);
		i++;
	}
}

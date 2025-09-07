/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_player_count_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 02:09:22 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/25 21:58:09 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	invalid_map_player(t_map *map)
{
	ft_printf("%sError%s\n", RED, END);
	ft_printf("%sThe map contains no player or more than one player%s\n",
		LIGHT_YELLOW, END);
	free_map(map);
	exit(EXIT_FAILURE);
}

int	inspect_player_count(t_map *map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (i < map->row)
	{
		j = 0;
		while (map->map[i][j] && j < map->col)
		{
			if (map->map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_collectibles_count.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 02:17:27 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/25 21:59:55 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_map_collectibles(t_map *map)
{
	ft_printf("%sError%s\n", RED, END);
	ft_printf("%sThe map contains no collectibles\n%s", LIGHT_YELLOW, END);
	free_map(map);
	exit(EXIT_FAILURE);
}

int	inspect_collectibles_count(t_map *map)
{
	int	i;
	int	j;
	int	collectibles;

	i = 0;
	collectibles = 0;
	while (i < map->row)
	{
		j = 0;
		while (map->map[i][j] && j < map->col)
		{
			if (map->map[i][j] == 'C')
				collectibles++;
			j++;
		}
		i++;
	}
	if (collectibles == 0)
		return (1);
	return (0);
}

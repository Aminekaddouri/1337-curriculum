/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_map_chars_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 02:00:16 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/25 21:58:22 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	invalid_map_chars(t_map *map)
{
	ft_printf("%sError%s\n", RED, END);
	ft_printf("%sThe map contains invalid characters%s\n", LIGHT_YELLOW, END);
	free_map(map);
	exit(EXIT_FAILURE);
}

int	inspect_map_chars(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (map->map[i][j] && j < map->col)
		{
			if (map->map[i][j] != '0' && map->map[i][j] != '1'
				&& map->map[i][j] != 'C' && map->map[i][j] != 'E'
				&& map->map[i][j] != 'P' && map->map[i][j] != 'Y')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_exit_count_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 02:19:22 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/25 21:58:56 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	invalid_map_exit(t_map *map)
{
	ft_printf("%sError%s\n", RED, END);
	ft_printf("%sThe map contains no exit or more than one exit%s\n",
		LIGHT_YELLOW, END);
	free_map(map);
	exit(EXIT_FAILURE);
}

int	inspect_exit_count(t_map *map)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (i < map->row)
	{
		j = 0;
		while (map->map[i][j] && j < map->col)
		{
			if (map->map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit != 1)
		return (1);
	return (0);
}

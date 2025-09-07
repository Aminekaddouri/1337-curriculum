/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 03:18:20 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/11 03:43:43 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->row)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

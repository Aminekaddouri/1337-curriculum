/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:06:10 by akaddour          #+#    #+#             */
/*   Updated: 2024/08/10 22:50:38 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	player_angle(t_cub *cub, int i, int j)
{
	if (cub->map.map_only[i][j] == 'N')
		cub->player.angle = 0;
	else if (cub->map.map_only[i][j] == 'S')
		cub->player.angle = M_PI;
	else if (cub->map.map_only[i][j] == 'W')
		cub->player.angle = (3 * M_PI) / 2;
	else if (cub->map.map_only[i][j] == 'E')
		cub->player.angle = M_PI / 2;
}

void	get_player_position(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map.map_only[i])
	{
		j = 0;
		while (cub->map.map_only[i][j])
		{
			if (cub->map.map_only[i][j] == 'N' || cub->map.map_only[i][j] == 'S'\
			|| cub->map.map_only[i][j] == 'E' || cub->map.map_only[i][j] == 'W')
			{
				cub->player.x = (j * WALL_SIZE) + WALL_SIZE / 2;
				cub->player.y = (i * WALL_SIZE) + WALL_SIZE / 2;
				player_angle(cub, i, j);
				cub->map.map_only[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

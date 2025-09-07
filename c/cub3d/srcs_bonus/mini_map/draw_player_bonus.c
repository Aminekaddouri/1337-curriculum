/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:56:38 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/14 18:08:11 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_player(t_cub *cub, int x, int y)
{
	int	top_x_y[2];
	int	px;
	int	py;
	int	i;
	int	j;

	px = cub->player.x - (x * WALL_SIZE);
	py = cub->player.y - (y * WALL_SIZE);
	top_x_y[0] = (px - (P_SIZE / 2)) * MINI_MAP_SCALE;
	top_x_y[1] = (py - (P_SIZE / 2)) * MINI_MAP_SCALE;
	i = 0;
	while (i < P_SIZE * MINI_MAP_SCALE)
	{
		j = 0;
		while (j < P_SIZE * MINI_MAP_SCALE)
		{
			my_mlx_pixel_put(cub, j + top_x_y[0],
				i + top_x_y[1], 0x000000FF);
			j++;
		}
		i++;
	}
}

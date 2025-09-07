/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:23:22 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/14 17:54:02 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_square(t_cub cub, int x, int y, int color)
{
	int	i;
	int	j;
	int	scaled_x;
	int	scaled_y;
	int	scaled_size;

	scaled_x = x * WALL_SIZE * MINI_MAP_SCALE;
	scaled_y = y * WALL_SIZE * MINI_MAP_SCALE;
	scaled_size = WALL_SIZE * MINI_MAP_SCALE;
	i = 0;
	while (i < scaled_size)
	{
		j = 0;
		while (j < scaled_size)
		{
			my_mlx_pixel_put(&cub, scaled_x + i, scaled_y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_square2(t_cub cub, int x, int y)
{
	int	i;
	int	j;
	int	scaled_x;
	int	scaled_y;
	int	scaled_size;

	scaled_x = x * WALL_SIZE * MINI_MAP_SCALE;
	scaled_y = y * WALL_SIZE * MINI_MAP_SCALE;
	scaled_size = WALL_SIZE * MINI_MAP_SCALE;
	i = 0;
	while (i < scaled_size)
	{
		j = 0;
		while (j < scaled_size)
		{
			if (i == 0 || i == scaled_size - 1
				|| j == 0 || j == scaled_size - 1)
				my_mlx_pixel_put(&cub, scaled_x + i, scaled_y + j, 0x00191919);
			else
				my_mlx_pixel_put(&cub, scaled_x + i, scaled_y + j, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}

void	calculate_y(t_cub *cub)
{
	int	rem;

	cub->map.y[0] = (cub->player.y / WALL_SIZE) - MINI_MAP_H;
	cub->map.y[1] = (cub->player.y / WALL_SIZE) + MINI_MAP_H;
	if (cub->map.y[0] < 0)
		cub->map.y[0] = 0;
	if (cub->map.y[1] > cub->map.height)
	{
		rem = cub->map.y[1] - cub->map.height;
		cub->map.y[0] -= rem;
		if (cub->map.y[0] < 0)
			cub->map.y[0] = 0;
		cub->map.y[1] = cub->map.height;
	}
	else if (cub->player.y / WALL_SIZE < MINI_MAP_H)
	{
		rem = MINI_MAP_H - (cub->player.y / WALL_SIZE) + 1;
		cub->map.y[1] += rem;
		if (cub->map.y[1] > cub->map.height)
			cub->map.y[1] = cub->map.height;
	}
}

void	calculate_x(t_cub *cub)
{
	int	rem;

	cub->map.x[0] = (cub->player.x / WALL_SIZE) - MINI_MAP_W;
	cub->map.x[1] = (cub->player.x / WALL_SIZE) + MINI_MAP_W;
	if (cub->map.x[0] < 0)
		cub->map.x[0] = 0;
	if (cub->map.x[1] > cub->map.width)
	{
		rem = cub->map.x[1] - cub->map.width;
		cub->map.x[0] -= rem;
		if (cub->map.x[0] < 0)
			cub->map.x[0] = 0;
		cub->map.x[1] = cub->map.width;
	}
	else if (cub->player.x / WALL_SIZE < MINI_MAP_W)
	{
		rem = MINI_MAP_W - (cub->player.x / WALL_SIZE) + 1;
		cub->map.x[1] += rem;
		if (cub->map.x[1] > cub->map.width)
			cub->map.x[1] = cub->map.width;
	}
}

void	draw_mini_map(t_cub cub)
{
	int	i;
	int	j;

	calculate_y(&cub);
	i = -1;
	while (++i < cub.map.y[1] - cub.map.y[0])
	{
		calculate_x(&cub);
		j = -1;
		while (++j < cub.map.x[1] - cub.map.x[0])
		{
			if (cub.map.map_only[i + cub.map.y[0]][j + cub.map.x[0]] == '1')
				draw_square(cub, j, i, 0x00191919);
			else if (cub.map.map_only[i + cub.map.y[0]][j
				+ cub.map.x[0]] == 'D')
				draw_square(cub, j, i, 0x00DAA06D);
			else if (cub.map.map_only[i + cub.map.y[0]][j
				+ cub.map.x[0]] == 'O')
				draw_square(cub, j, i, 0x00808000);
			else if (cub.map.map_only[i
					+ cub.map.y[0]][j + cub.map.x[0]] == '0')
				draw_square2(cub, j, i);
		}
	}
	draw_player(&cub, cub.map.x[0], cub.map.y[0]);
}

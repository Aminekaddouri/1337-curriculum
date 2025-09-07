/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:45:18 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/14 17:42:32 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_wall(int x, int y, t_cub *cub)
{
	int	map_x;
	int	map_y;

	map_x = x / WALL_SIZE;
	map_y = y / WALL_SIZE;
	return (cub->map.map_only[map_y][map_x] == '1');
}

int	close_window(t_cub *cub)
{
	int	i;

	i = 0;
	mlx_destroy_window(cub->mlx, cub->win);
	ft_free_map_content(cub->map.map_content);
	ft_free_map_content(cub->map.map_only);
	free(cub->map.east_texture);
	free(cub->map.west_texture);
	free(cub->map.south_texture);
	free(cub->map.north_texture);
	while (i < 4)
		mlx_destroy_image(cub->mlx, cub->textures[i++].img);
	mlx_destroy_image(cub->mlx, cub->img.img);
	free(cub->map.filename);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	exit(0);
}

void	key_press_arrow_right(t_cub *cub)
{
	cub->player.angle += 0.1 * P_ROTATION_SPEED;
	if (cub->player.angle > M_PI * 2)
		cub->player.angle -= M_PI * 2;
	cub->player.dx = cos(cub->player.angle) * P_SPEED;
	cub->player.dy = sin(cub->player.angle) * P_SPEED;
}

void	key_press_arrow_left(t_cub *cub)
{
	cub->player.angle -= 0.1 * P_ROTATION_SPEED;
	if (cub->player.angle < 0)
		cub->player.angle += M_PI * 2;
	cub->player.dx = cos(cub->player.angle) * P_SPEED;
	cub->player.dy = sin(cub->player.angle) * P_SPEED;
}

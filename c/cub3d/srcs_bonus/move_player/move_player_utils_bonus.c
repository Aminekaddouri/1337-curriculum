/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:45:18 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/14 17:54:02 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	is_wall(int x, int y, t_cub *cub)
{
	int	map_x;
	int	map_y;

	map_x = x / WALL_SIZE;
	map_y = y / WALL_SIZE;
	return (cub->map.map_only[map_y][map_x] == '1'
		|| cub->map.map_only[map_y][map_x] == 'D');
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
	i = 0;
	while (i < 8)
		mlx_destroy_image(cub->mlx, cub->door[i++].img);
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

void	open_door(t_cub *cub)
{
	int	map_x;
	int	map_y;
	int	player_map_x;
	int	player_map_y;

	player_map_x = cub->player.x / WALL_SIZE;
	player_map_y = cub->player.y / WALL_SIZE;
	map_x = (cub->player.x + cub->player.dx * 15) / WALL_SIZE;
	map_y = (cub->player.y + cub->player.dy * 15) / WALL_SIZE;
	if (cub->map.map_only[map_y][map_x] == 'D')
		cub->map.map_only[map_y][map_x] = 'O';
	else if (cub->map.map_only[map_y][map_x] == 'O')
	{
		if (!(player_map_x == map_x && player_map_y == map_y))
			cub->map.map_only[map_y][map_x] = 'D';
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 02:04:04 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/25 01:09:48 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_map_and_check_loss(t_map *map, int i, int old_x, int old_y)
{
	int	enemy_x;
	int	enemy_y;

	map->map[old_x][old_y] = EMPTY;
	enemy_x = map->enemy_positions[i][0];
	enemy_y = map->enemy_positions[i][1];
	map->map[enemy_x][enemy_y] = ENEMY;
	if (map->enemy_positions[i][0] == map->x
		&& map->enemy_positions[i][1] == map->y)
		ft_free(map, "You lost");
	map->enemy_current_frame = (map->enemy_current_frame + 1) % 8;
}

void	update_enemy_direction(t_map *map, int i)
{
	if ((map->enemy_positions[i][1] == map->col - 1)
		|| (map->map[map->enemy_positions[i][0]]
		[map->enemy_positions[i][1] + 1] == WALL)
		|| (map->map[map->enemy_positions[i][0]]
		[map->enemy_positions[i][1] + 1] == COL))
		map->enemy_direction[i] = 'L';
	else if ((map->enemy_positions[i][1] == 0)
		|| (map->map[map->enemy_positions[i][0]]
		[map->enemy_positions[i][1] - 1] == WALL)
		|| (map->map[map->enemy_positions[i][0]]
		[map->enemy_positions[i][1] - 1] == COL))
		map->enemy_direction[i] = 'R';
}

void	update_enemy_position(t_map *map, int i)
{
	if (map->enemy_direction[i] == 'R'
		&& map->map[map->enemy_positions[i][0]]
		[map->enemy_positions[i][1] + 1] != WALL
		&& map->map[map->enemy_positions[i][0]]
		[map->enemy_positions[i][1] + 1] != COL)
		map->enemy_positions[i][1]++;
	else if (map->enemy_direction[i] == 'L'
		&& map->map[map->enemy_positions[i][0]]
		[map->enemy_positions[i][1] - 1] != WALL
		&& map->map[map->enemy_positions[i][0]]
		[map->enemy_positions[i][1] - 1] != COL)
		map->enemy_positions[i][1]--;
}

void	enemy_move(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->enemy_count)
	{
		map->old_x = map->enemy_positions[i][0];
		map->old_y = map->enemy_positions[i][1];
		update_enemy_direction(map, i);
		update_enemy_position(map, i);
		update_map_and_check_loss(map, i, map->old_x, map->old_y);
	}
}

int	loop_hook(t_map *map)
{
	mlx_clear_window(map->mlx, map->win);
	map->loop_counter++;
	if (map->loop_counter % 10 == 0)
	{
		enemy_move(map);
		map->loop_counter = 0;
	}
	ft_render_images(map);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_image_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:04:13 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/26 00:42:14 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*get_enemy_image(t_map *map, int enemy_index)
{
	if (map->enemy_direction[enemy_index] == 'L')
		return (map->enemy_left_frames[map->enemy_current_frame]);
	else
		return (map->enemy_right_frames[map->enemy_current_frame]);
}

char	*get_player_image(t_map *map)
{
	if (map->player_direction == 'L')
		return (map->player_left_frame[map->current_frame]);
	else
		return (map->player_right_frame[map->current_frame]);
}

char	*ft_get_image(t_map *map, char c, int can_exit, int enemy_index)
{
	char	*output;

	output = NULL;
	if (c == EMPTY)
		output = "sprites/empty.xpm";
	else if (c == WALL)
		output = "sprites/wall.xpm";
	else if (c == PLAYER)
		return (get_player_image(map));
	else if (c == ENEMY)
		return (get_enemy_image(map, enemy_index));
	else if (c == COL)
		output = "sprites/col.xpm";
	else if (c == EXIT)
	{
		if (can_exit)
			output = "sprites/exit_open.xpm";
		else
			output = "sprites/exit_closed.xpm";
	}
	return (output);
}

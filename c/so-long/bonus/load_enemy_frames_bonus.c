/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_enemy_frames_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:44:46 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/26 00:40:30 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemy_frames(t_map *map)
{
	map->enemy_current_frame = 0;
	map->enemy_right_frames[0] = "./bonus/sprites/enemy/Walk_right_01.xpm";
	map->enemy_right_frames[1] = "./bonus/sprites/enemy/Walk_right_02.xpm";
	map->enemy_right_frames[2] = "./bonus/sprites/enemy/Walk_right_03.xpm";
	map->enemy_right_frames[3] = "./bonus/sprites/enemy/Walk_right_04.xpm";
	map->enemy_right_frames[4] = "./bonus/sprites/enemy/Walk_right_05.xpm";
	map->enemy_right_frames[5] = "./bonus/sprites/enemy/Walk_right_06.xpm";
	map->enemy_right_frames[6] = "./bonus/sprites/enemy/Walk_right_07.xpm";
	map->enemy_right_frames[7] = "./bonus/sprites/enemy/Walk_right_08.xpm";
	map->enemy_left_frames[0] = "./bonus/sprites/enemy/Walk_left_01.xpm";
	map->enemy_left_frames[1] = "./bonus/sprites/enemy/Walk_left_02.xpm";
	map->enemy_left_frames[2] = "./bonus/sprites/enemy/Walk_left_03.xpm";
	map->enemy_left_frames[3] = "./bonus/sprites/enemy/Walk_left_04.xpm";
	map->enemy_left_frames[4] = "./bonus/sprites/enemy/Walk_left_05.xpm";
	map->enemy_left_frames[5] = "./bonus/sprites/enemy/Walk_left_06.xpm";
	map->enemy_left_frames[6] = "./bonus/sprites/enemy/Walk_left_07.xpm";
	map->enemy_left_frames[7] = "./bonus/sprites/enemy/Walk_left_08.xpm";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_frames_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 01:12:53 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/24 00:27:25 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_player_frames(t_map *map)
{
	map->current_frame = 0;
	map->player_right_frame[0] = "./bonus/sprites/Walk_right/Walk_right_01.xpm";
	map->player_right_frame[1] = "./bonus/sprites/Walk_right/Walk_right_02.xpm";
	map->player_right_frame[2] = "./bonus/sprites/Walk_right/Walk_right_03.xpm";
	map->player_right_frame[3] = "./bonus/sprites/Walk_right/Walk_right_04.xpm";
	map->player_right_frame[4] = "./bonus/sprites/Walk_right/Walk_right_05.xpm";
	map->player_right_frame[5] = "./bonus/sprites/Walk_right/Walk_right_06.xpm";
	map->player_right_frame[6] = "./bonus/sprites/Walk_right/Walk_right_07.xpm";
	map->player_right_frame[7] = "./bonus/sprites/Walk_right/Walk_right_08.xpm";
	map->player_left_frame[0] = "./bonus/sprites/Walk_left/Walk_left_01.xpm";
	map->player_left_frame[1] = "./bonus/sprites/Walk_left/Walk_left_02.xpm";
	map->player_left_frame[2] = "./bonus/sprites/Walk_left/Walk_left_03.xpm";
	map->player_left_frame[3] = "./bonus/sprites/Walk_left/Walk_left_04.xpm";
	map->player_left_frame[4] = "./bonus/sprites/Walk_left/Walk_left_05.xpm";
	map->player_left_frame[5] = "./bonus/sprites/Walk_left/Walk_left_06.xpm";
	map->player_left_frame[6] = "./bonus/sprites/Walk_left/Walk_left_07.xpm";
	map->player_left_frame[7] = "./bonus/sprites/Walk_left/Walk_left_08.xpm";
}

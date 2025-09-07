/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:40:27 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/25 21:58:33 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	void	ft_check(char *file, t_map *map)
{
	if (!is_map_valid(map, file))
	{
		ft_printf("%sError%s\n", RED, END);
		ft_printf("%sThe map is not valid. The player %s%s\n",
			LIGHT_YELLOW, MAP_ERROR, END);
		exit(EXIT_FAILURE);
	}
}

void	inspect_map(char *file, t_map *map)
{
	inspect_file(file);
	if (inspect_file_extension(file, ".ber"))
		invalid_file_extension(file);
	load_map(file, map);
	if (inspect_rectangular_form(map))
		invalid_map_form(map);
	if (inspect_wall_boundaries(map))
		invalid_map_walls(map);
	if (inspect_map_chars(map))
		invalid_map_chars(map);
	if (inspect_player_count(map))
		invalid_map_player(map);
	if (inspect_collectibles_count(map))
		invalid_map_collectibles(map);
	if (inspect_exit_count(map))
		invalid_map_exit(map);
	count_collectibles(map);
	get_player_position(map);
	get_exit_position(map);
	count_enemies(map);
	get_enemy_positions(map);
	ft_check(file, map);
	load_map(file, map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 01:43:56 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/02 00:16:58 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (key == ESC_KEY)
		ft_free(map, "Goodbye!\n");
	else if (key == RIGHT_KEY)
		ft_move_right(map);
	else if (key == LEFT_KEY)
		ft_move_left(map);
	else if (key == UP_KEY)
		ft_move_up(map);
	else if (key == DOWN_KEY)
		ft_move_down(map);
	mlx_clear_window(map->mlx, map->win);
	ft_render_images(*map);
	return (0);
}

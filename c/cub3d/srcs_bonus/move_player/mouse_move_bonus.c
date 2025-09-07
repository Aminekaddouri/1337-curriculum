/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:08:57 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/14 17:54:02 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	mouse_move(int x, int y, t_cub *cub)
{
	int	delta_x;

	(void) y;
	delta_x = x - cub->prev_mouse_x;
	cub->player.angle += (delta_x * (M_PI / 180)) * SENSITIVITY;
	cub->player.angle = fmod(cub->player.angle, 2 * M_PI);
	if (cub->player.angle < 0)
		cub->player.angle += 2 * M_PI;
	cub->player.dx = cos(cub->player.angle) * P_SPEED;
	cub->player.dy = sin(cub->player.angle) * P_SPEED;
	cub->prev_mouse_x = x;
	return (0);
}

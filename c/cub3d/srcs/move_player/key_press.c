/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:08:57 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/14 18:47:52 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	key_press_w(t_cub *cub)
{
	double	new_x;
	double	new_y;
	int		margin;

	new_x = cub->player.x + cub->player.dx;
	new_y = cub->player.y + cub->player.dy;
	margin = 5;
	if (!is_wall(new_x + margin, new_y + margin, cub)
		&& !is_wall(new_x + margin, new_y - margin, cub)
		&& !is_wall(new_x - margin, new_y + margin, cub)
		&& !is_wall(new_x - margin, new_y - margin, cub))
	{
		cub->player.x = new_x;
		cub->player.y = new_y;
	}
}

static void	key_press_s(t_cub *cub)
{
	double	new_x;
	double	new_y;
	int		margin;

	new_x = cub->player.x - cub->player.dx;
	new_y = cub->player.y - cub->player.dy;
	margin = 5;
	if (!is_wall(new_x + margin, new_y + margin, cub)
		&& !is_wall(new_x + margin, new_y - margin, cub)
		&& !is_wall(new_x - margin, new_y + margin, cub)
		&& !is_wall(new_x - margin, new_y - margin, cub))
	{
		cub->player.x = new_x;
		cub->player.y = new_y;
	}
}

static void	key_press_d(t_cub *cub)
{
	double	new_x;
	double	new_y;
	int		margin;

	new_x = cub->player.x - cub->player.dy;
	new_y = cub->player.y + cub->player.dx;
	margin = 5;
	if (!is_wall(new_x + margin, new_y + margin, cub)
		&& !is_wall(new_x + margin, new_y - margin, cub)
		&& !is_wall(new_x - margin, new_y + margin, cub)
		&& !is_wall(new_x - margin, new_y - margin, cub))
	{
		cub->player.x = new_x;
		cub->player.y = new_y;
	}
}

static void	key_press_a(t_cub *cub)
{
	double	new_x;
	double	new_y;
	int		margin;

	new_x = cub->player.x + cub->player.dy;
	new_y = cub->player.y - cub->player.dx;
	margin = 5;
	if (!is_wall(new_x + margin, new_y + margin, cub)
		&& !is_wall(new_x + margin, new_y - margin, cub)
		&& !is_wall(new_x - margin, new_y + margin, cub)
		&& !is_wall(new_x - margin, new_y - margin, cub))
	{
		cub->player.x = new_x;
		cub->player.y = new_y;
	}
}

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == RIGHT_ARROW)
		key_press_arrow_right(cub);
	else if (keycode == LEFT_ARROW)
		key_press_arrow_left(cub);
	else if (keycode == W_KEY)
		key_press_w(cub);
	else if (keycode == S_KEY)
		key_press_s(cub);
	else if (keycode == A_KEY)
		key_press_a(cub);
	else if (keycode == D_KEY)
		key_press_d(cub);
	else if (keycode == ESC)
		close_window(cub);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_horiz_ray_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:28:45 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/14 17:54:02 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static t_bool	help_function(t_cub cub, t_ray *ray, t_cast_ray *horiz)
{
	int	y_to_test;
	int	map_xy[2];

	y_to_test = horiz->next_touch_y;
	if (ray->is_facing_up)
		y_to_test--;
	map_xy[0] = (int)(horiz->next_touch_x / WALL_SIZE);
	map_xy[1] = (int)(y_to_test / WALL_SIZE);
	if (map_xy[1] >= cub.map.height)
		map_xy[1] = cub.map.height - 1;
	if (cub.map.map_only[map_xy[1]][map_xy[0]] == '1'
		|| cub.map.map_only[map_xy[1]][map_xy[0]] == 'D')
	{
		horiz->wall_hit_x = horiz->next_touch_x;
		horiz->wall_hit_y = horiz->next_touch_y;
		if (cub.map.map_only[map_xy[1]][map_xy[0]] == 'D')
			horiz->is_door = 1;
		return (true);
	}
	else
	{
		horiz->next_touch_x += horiz->x_step;
		horiz->next_touch_y += horiz->y_step;
	}
	return (false);
}

static t_bool	get_horiz_hit(t_cub cub, t_ray *ray, t_cast_ray *horiz)
{
	while (horiz->next_touch_x >= 0 && horiz->next_touch_x <= cub.screen_w
		&& horiz->next_touch_y >= 0 && horiz->next_touch_y <= cub.screen_h)
	{
		if (help_function(cub, ray, horiz))
			return (true);
	}
	return (false);
}

t_bool	cast_horiz_ray(t_cub cub, t_ray *ray, t_cast_ray *horiz)
{
	horiz->y_intercept = floor(cub.player.y / WALL_SIZE) * WALL_SIZE;
	if (ray->is_facing_down)
		horiz->y_intercept += WALL_SIZE;
	horiz->x_intercept = ((horiz->y_intercept - cub.player.y)
			/ tan(ray->ray_angle)) + cub.player.x;
	horiz->y_step = WALL_SIZE;
	if (ray->is_facing_up)
		horiz->y_step *= -1;
	horiz->x_step = WALL_SIZE / tan(ray->ray_angle);
	if (ray->is_facing_left && horiz->x_step > 0)
		horiz->x_step *= -1;
	if (ray->is_facing_right && horiz->x_step < 0)
		horiz->x_step *= -1;
	horiz->next_touch_x = horiz->x_intercept;
	horiz->next_touch_y = horiz->y_intercept;
	return (get_horiz_hit(cub, ray, horiz));
}

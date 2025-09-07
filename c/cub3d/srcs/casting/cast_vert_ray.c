/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_vert_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:29:42 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/14 17:28:03 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_bool	help_function(t_cub cub, t_ray *ray, t_cast_ray *vert)
{
	int	x_to_test;
	int	map_xy[2];

	x_to_test = vert->next_touch_x;
	if (ray->is_facing_left)
		x_to_test--;
	map_xy[0] = (int)(x_to_test / WALL_SIZE);
	map_xy[1] = (int)(vert->next_touch_y / WALL_SIZE);
	if (map_xy[0] >= cub.map.width)
		map_xy[0] = cub.map.width - 1;
	if (cub.map.map_only[map_xy[1]][map_xy[0]] == '1'
		|| cub.map.map_only[map_xy[1]][map_xy[0]] == 'D')
	{
		vert->wall_hit_x = vert->next_touch_x;
		vert->wall_hit_y = vert->next_touch_y;
		return (true);
	}
	else
	{
		vert->next_touch_x += vert->x_step;
		vert->next_touch_y += vert->y_step;
	}
	return (false);
}

static t_bool	get_vert_hit(t_cub cub, t_ray *ray, t_cast_ray *vert)
{
	while (vert->next_touch_x >= 0 && vert->next_touch_x <= cub.screen_w
		&& vert->next_touch_y >= 0 && vert->next_touch_y <= cub.screen_h)
	{
		if (help_function(cub, ray, vert))
			return (true);
	}
	return (false);
}

t_bool	cast_vert_ray(t_cub cub, t_ray *ray, t_cast_ray *vert)
{
	vert->x_intercept = floor(cub.player.x / WALL_SIZE) * WALL_SIZE;
	if (ray->is_facing_right)
		vert->x_intercept += WALL_SIZE;
	vert->y_intercept = ((vert->x_intercept - cub.player.x)
			* tan(ray->ray_angle)) + cub.player.y;
	vert->x_step = WALL_SIZE;
	if (ray->is_facing_left)
		vert->x_step *= -1;
	vert->y_step = WALL_SIZE * tan(ray->ray_angle);
	if (ray->is_facing_up && vert->y_step > 0)
		vert->y_step *= -1;
	if (ray->is_facing_down && vert->y_step < 0)
		vert->y_step *= -1;
	vert->next_touch_x = vert->x_intercept;
	vert->next_touch_y = vert->y_intercept;
	return (get_vert_hit(cub, ray, vert));
}

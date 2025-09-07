/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:41:27 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/14 17:27:31 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	compare_distances(t_ray *ray, t_cast_ray horiz, t_cast_ray vert)
{
	if (horiz.distance < vert.distance)
	{
		ray->wall_hit_x = horiz.wall_hit_x;
		ray->wall_hit_y = horiz.wall_hit_y;
		ray->distance = horiz.distance;
	}
	else
	{
		ray->wall_hit_x = vert.wall_hit_x;
		ray->wall_hit_y = vert.wall_hit_y;
		ray->distance = vert.distance;
		ray->is_hit_vert = 1;
	}
}

void	cast_ray(t_cub cub, t_ray *ray)
{
	t_cast_ray	horiz_ray;
	t_cast_ray	vert_ray;
	t_bool		found_horz_wall_hit;
	t_bool		found_vert_wall_hit;

	found_horz_wall_hit = cast_horiz_ray(cub, ray, &horiz_ray);
	found_vert_wall_hit = cast_vert_ray(cub, ray, &vert_ray);
	if (found_horz_wall_hit)
		horiz_ray.distance = get_distance(cub.player.x,
				cub.player.y, horiz_ray.wall_hit_x, horiz_ray.wall_hit_y);
	else
		horiz_ray.distance = INT_MAX;
	if (found_vert_wall_hit)
		vert_ray.distance = get_distance(cub.player.x,
				cub.player.y, vert_ray.wall_hit_x, vert_ray.wall_hit_y);
	else
		vert_ray.distance = INT_MAX;
	compare_distances(ray, horiz_ray, vert_ray);
}

void	cast_all_rays(t_cub *cub)
{
	int		i;
	double	ray_angle;
	t_ray	ray;

	ray_angle = cub->player.angle - (FOV_ANGLE / 2);
	i = 0;
	while (i < cub->nbr_rays)
	{
		ray.index = i;
		ray.ray_angle = fmod(ray_angle, 2 * M_PI);
		if (ray.ray_angle < 0)
			ray.ray_angle += 2 * M_PI;
		ray.is_facing_down = ray.ray_angle > 0 && ray.ray_angle < M_PI;
		ray.is_facing_up = !ray.is_facing_down;
		ray.is_facing_right = ray_angle < M_PI / 2
			|| ray_angle > (3 * M_PI) / 2;
		ray.is_facing_left = !ray.is_facing_right;
		ray.is_hit_vert = 0;
		cast_ray(*cub, &ray);
		render_wall(cub, ray, i);
		ray_angle += FOV_ANGLE / cub->nbr_rays;
		i++;
	}
}

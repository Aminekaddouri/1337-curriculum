/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:43:21 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/28 15:05:06 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

t_texture	get_correct_texture(t_cub *cub, t_ray ray)
{
	t_texture	texture;

	if (ray.is_hit_vert && ray.is_facing_right)
		texture = cub->textures[0];
	else if (ray.is_hit_vert && ray.is_facing_left)
		texture = cub->textures[1];
	else if (!ray.is_hit_vert && ray.is_facing_up)
		texture = cub->textures[2];
	else
		texture = cub->textures[3];
	return (texture);
}

static void	help_function(t_cub *cub, t_ray ray, t_render *render)
{
	if (ray.is_door)
		render->texture = cub->door[cub->current_frame];
	else
		render->texture = get_correct_texture(cub, ray);
	if (ray.is_hit_vert)
		render->texur_x = (int)ray.wall_hit_y % render->texture.width;
	else
		render->texur_x = (int)ray.wall_hit_x % render->texture.width;
}

void	render_textures(t_cub *cub, t_ray ray, \
	int w_top_p, int w_bottom_p)
{
	t_render	render;

	help_function(cub, ray, &render);
	while (w_top_p < w_bottom_p)
	{
		render.distance_from_top = w_top_p + (cub->wall_h / 2) - (SCREEN_H / 2);
		render.texur_y = render.distance_from_top
			* ((double)render.texture.height / cub->wall_h);
		if (render.texur_x >= 0 && render.texur_x < render.texture.width
			&& render.texur_y >= 0 && render.texur_y < render.texture.height)
		{
			render.color = *(int *)(render.texture.addr
					+ (render.texur_y * render.texture.line_length
						+ render.texur_x * (render.texture.bpp / 8)));
			if (render.color != -16777216)
				my_mlx_pixel_put(cub, ray.index, w_top_p, render.color);
			else
			{
				render.color = create_color(255, cub->map.ceiling_color.r,
						cub->map.ceiling_color.g, cub->map.ceiling_color.b);
				my_mlx_pixel_put(cub, ray.index, w_top_p, render.color);
			}
		}
		w_top_p++;
	}
}

void	render_floor_ceiling(t_cub *cub, int wall_top_pixel, \
	int wall_bottom_pixel, int i)
{
	t_rec	floor_rec;
	t_rec	ceiling_rec;

	floor_rec.x0 = i;
	floor_rec.y0 = 0;
	floor_rec.x1 = i + COLUMN_W - 1;
	floor_rec.y1 = wall_top_pixel - 1;
	floor_rec.color = create_color(255, cub->map.ceiling_color.r,
			cub->map.ceiling_color.g, cub->map.ceiling_color.b);
	ceiling_rec.x0 = i;
	ceiling_rec.y0 = wall_bottom_pixel;
	ceiling_rec.x1 = i + COLUMN_W - 1;
	ceiling_rec.y1 = SCREEN_H;
	ceiling_rec.color = create_color(255, cub->map.floor_color.r,
			cub->map.floor_color.g, cub->map.floor_color.b);
	draw_rec(cub, floor_rec);
	draw_rec(cub, ceiling_rec);
}

void	render_wall(t_cub *cub, t_ray ray, int i)
{
	double		ray_distance;
	double		distance_projection;
	int			wall_top_pixel;
	int			wall_bottom_pixel;

	distance_projection = (SCREEN_W / 2) / tan(FOV_ANGLE / 2);
	ray_distance = ray.distance * cos(ray.ray_angle - cub->player.angle);
	if (ray_distance == 0)
		return ;
	cub->wall_h = (WALL_SIZE / ray_distance) * distance_projection;
	wall_top_pixel = (SCREEN_H / 2) - (cub->wall_h / 2);
	if (wall_top_pixel < 0)
		wall_top_pixel = 0;
	if (wall_top_pixel >= SCREEN_H)
		wall_top_pixel = SCREEN_H - 1;
	wall_bottom_pixel = (SCREEN_H / 2) + (cub->wall_h / 2);
	if (wall_bottom_pixel >= SCREEN_H)
		wall_bottom_pixel = SCREEN_H;
	if (wall_bottom_pixel < 0)
		wall_bottom_pixel = 0;
	render_textures(cub, ray, wall_top_pixel, wall_bottom_pixel);
	render_floor_ceiling(cub, wall_top_pixel, wall_bottom_pixel, i);
}

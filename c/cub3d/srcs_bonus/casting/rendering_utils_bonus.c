/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:44:33 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/14 17:54:02 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

unsigned int	create_color(int alpha, int red, int green, int blue)
{
	return (((alpha & 0xFF) << 24) | ((red & 0xFF) << 16)
		| ((green & 0xFF) << 8) | (blue & 0xFF));
}

void	draw_rec(t_cub *cub, t_rec rec)
{
	int	i;
	int	j;

	i = rec.y0;
	while (i <= rec.y1)
	{
		j = rec.x0;
		while (j <= rec.x1)
		{
			my_mlx_pixel_put(cub, j, i, rec.color);
			j++;
		}
		i++;
	}
}

double	get_distance(double x0, double y0, double x1, double y1)
{
	return (sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)));
}

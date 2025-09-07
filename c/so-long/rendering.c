/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 12:52:42 by ael-khni          #+#    #+#             */
/*   Updated: 2024/02/26 00:40:02 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_get_image(t_map *map, char c, int can_exit)
{
	char	*output;

	output = NULL;
	if (c == EMPTY)
		output = "sprites/empty.xpm";
	else if (c == WALL)
		output = "sprites/wall.xpm";
	else if (c == PLAYER)
	{
		if (map->player_direction == 'L')
			output = "sprites/Walk_left.xpm";
		else
			output = "sprites/player.xpm";
	}
	else if (c == COL)
		output = "sprites/col.xpm";
	else if (c == EXIT)
	{
		if (can_exit)
			output = "sprites/exit_open.xpm";
		else
			output = "sprites/exit_closed.xpm";
	}
	return (output);
}

void	render_images_action(t_map map, int x, int y)
{
	char	*img_path;

	if (map.collectibles == 0)
		map.can_exit = 1;
	img_path = ft_get_image(&map, map.map[x][y], map.can_exit);
	if (img_path)
	{
		map.img_ptr = mlx_xpm_file_to_image(map.mlx, img_path,
				&map.img_size, &map.img_size);
		if (map.img_ptr == NULL)
			ft_free(&map, "Error\nInvalid image path");
		mlx_put_image_to_window(map.mlx, map.win, map.img_ptr,
			y * SQUARE, x * SQUARE);
		mlx_destroy_image(map.mlx, map.img_ptr);
	}
}

void	ft_render_images(t_map map)
{
	int		x;
	int		y;
	char	original;

	map.img_size = SQUARE;
	x = 0;
	while (map.map[x])
	{
		y = 0;
		while (map.map[x][y] != '\n' && map.map[x][y])
		{
			original = map.map[x][y];
			map.map[x][y] = EMPTY;
			render_images_action(map, x, y);
			map.map[x][y] = original;
			render_images_action(map, x, y);
			y++;
		}
		x++;
	}
}

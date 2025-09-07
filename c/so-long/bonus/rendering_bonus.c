/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 12:52:42 by ael-khni          #+#    #+#             */
/*   Updated: 2024/02/26 00:36:07 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_enemy_index(t_map *map, int x, int y)
{
	int	i;

	i = 0;
	while (i < map->enemy_count)
	{
		if (map->enemy_positions[i][0] == x && map->enemy_positions[i][1] == y)
			return (i);
		i++;
	}
	return (-1);
}

void	render_images_action(t_map *map, int x, int y)
{
	char	*img_path;
	int		enemy_index;

	map->can_exit = 0;
	if (map->collectibles == 0)
		map->can_exit = 1;
	enemy_index = get_enemy_index(map, x, y);
	img_path = ft_get_image(map, map->map[x][y], map->can_exit, enemy_index);
	if (img_path)
	{
		map->img_ptr = mlx_xpm_file_to_image(map->mlx, img_path,
				&map->img_size, &map->img_size);
		if (map->img_ptr == NULL)
			ft_free(map, "Error\nInvalid image path");
		mlx_put_image_to_window(map->mlx, map->win, map->img_ptr,
			y * SQUARE, x * SQUARE);
		mlx_destroy_image(map->mlx, map->img_ptr);
	}
}

static	void	put_str_to_window(t_map *map)
{
	char	*str;
	char	*num;

	num = ft_itoa(map->mv_count);
	str = ft_strjoin("Moves: ", num);
	mlx_string_put(map->mlx, map->win, 5,
		5, 0x00ff00, str);
	free(num);
	free(str);
}

void	ft_render_images(t_map	*map)
{
	int		x;
	int		y;
	char	original;

	map->img_size = SQUARE;
	x = 0;
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y] != '\n' && map->map[x][y])
		{
			original = map->map[x][y];
			map->map[x][y] = EMPTY;
			render_images_action(map, x, y);
			map->map[x][y] = original;
			render_images_action(map, x, y);
			y++;
		}
		x++;
	}
	put_str_to_window(map);
}

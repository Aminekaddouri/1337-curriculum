/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:46:15 by akaddour          #+#    #+#             */
/*   Updated: 2024/08/26 16:24:32 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_map_content(char **map_content)
{
	int	i;

	if (!map_content)
		return ;
	i = 0;
	while (map_content[i])
	{
		free(map_content[i]);
		i++;
	}
	free(map_content);
}

void	ft_puterror(t_cub *cub, char *msg)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	if (cub->map.map_content)
		ft_free_map_content(cub->map.map_content);
	if (cub->map.map_only)
		ft_free_map_content(cub->map.map_only);
	if (cub->map.north_texture)
		free(cub->map.north_texture);
	if (cub->map.south_texture)
		free(cub->map.south_texture);
	if (cub->map.west_texture)
		free(cub->map.west_texture);
	if (cub->map.east_texture)
		free(cub->map.east_texture);
	if (cub->map.filename)
		free(cub->map.filename);
	exit(EXIT_FAILURE);
}

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->img.addr + (y * cub->img.line_length
			+ x * (cub->img.bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

static void	ft_free(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (cub->textures[i].img)
			mlx_destroy_image(cub->mlx, cub->textures[i].img);
	}
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_image(cub->mlx, cub->img.img);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	ft_puterror(cub, "Empty or invalid xpm file\n");
}

t_texture	load_xpm(t_cub *cub, char *path)
{
	t_texture	texture;

	texture.img = mlx_xpm_file_to_image(cub->mlx,
			path, &texture.width, &texture.height);
	if (!texture.img)
		ft_free(cub);
	texture.addr = mlx_get_data_addr(texture.img,
			&texture.bpp, &texture.line_length, &texture.endian);
	return (texture);
}

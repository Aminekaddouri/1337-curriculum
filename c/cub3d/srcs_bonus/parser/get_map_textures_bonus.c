/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:23:49 by akaddour          #+#    #+#             */
/*   Updated: 2024/08/14 17:54:02 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

char	*trim_newline(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
	return (str);
}

void	assign_texture(t_cub *cub, char **line)
{
	if (line[1] && ft_strcmp(line[0], NORTH_TEXTURE) == EQUAL)
		cub->map.north_texture = ft_strdup(trim_newline(line[1]));
	else if (line[1] && ft_strcmp(line[0], SOUTH_TEXTURE) == EQUAL)
		cub->map.south_texture = ft_strdup(trim_newline(line[1]));
	else if (line[1] && ft_strcmp(line[0], EAST_TEXTURE) == EQUAL)
		cub->map.east_texture = ft_strdup(trim_newline(line[1]));
	else if (line[1] && ft_strcmp(line[0], WEST_TEXTURE) == EQUAL)
		cub->map.west_texture = ft_strdup(trim_newline(line[1]));
}

void	check_texture_errors(t_cub *cub)
{
	if (!cub->map.north_texture || !cub->map.south_texture
		|| !cub->map.east_texture || !cub->map.west_texture)
		ft_puterror(cub, "Texture error! One or more textures are missing.\n");
	if (open(cub->map.north_texture, O_RDONLY) < 0
		|| open(cub->map.south_texture, O_RDONLY) < 0
		|| open(cub->map.east_texture, O_RDONLY) < 0
		|| open(cub->map.west_texture, O_RDONLY) < 0)
		ft_puterror(cub, "Texture doesn't exist!\n");
}

void	get_map_textures(t_cub *cub)
{
	char	**line;
	int		i;

	i = 0;
	while (cub->map.map_content[i])
	{
		if (is_whitespace_line(cub->map.map_content[i]))
		{
			i++;
			continue ;
		}
		line = ft_split_set(cub->map.map_content[i], " \t\n");
		if ((line[0][0] == 'N' || line[0][0] == 'S' || line[0][0] == 'W'
			|| line[0][0] == 'E') && ft_tablen(line) > 2 && line[2])
		{
			free_split(line);
			ft_puterror(cub, "Texture error! Only allowed one texture.\n");
		}
		assign_texture(cub, line);
		free_split(line);
		i++;
	}
	check_texture_errors(cub);
}

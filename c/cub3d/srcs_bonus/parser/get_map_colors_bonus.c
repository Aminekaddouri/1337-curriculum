/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_colors_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:38:08 by akaddour          #+#    #+#             */
/*   Updated: 2024/08/22 14:56:16 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	parse_color_value(t_cub *cub, char *str, char **colors, char *new_line)
{
	int	value;

	value = ft_atoi(str);
	if (value < 0 || value > 255)
	{
		free_split(colors);
		free(str);
		free(new_line);
		ft_puterror(cub, "Invalid color value! \
It should be between 0 and 255.\n");
	}
	return (value);
}

void	set_color(t_cub *cub, t_color *color, char **colors, char *new_line)
{
	char	*trimmed_color;

	trimmed_color = ft_strtrim(colors[0], " \t\n");
	color->r = parse_color_value(cub, trimmed_color, colors, new_line);
	free(trimmed_color);
	trimmed_color = ft_strtrim(colors[1], " \t\n");
	color->g = parse_color_value(cub, trimmed_color, colors, new_line);
	free(trimmed_color);
	trimmed_color = ft_strtrim(colors[2], " \t\n");
	color->b = parse_color_value(cub, trimmed_color, colors, new_line);
	free(trimmed_color);
}

void	check_color_count(t_cub *cub, int count, char *new_line)
{
	if (count != 2)
	{
		free(new_line);
		ft_puterror(cub, "Color error! Missing or more than 3 colors.\n");
	}
}

void	process_color_line(t_cub *cub, char *line, char type)
{
	char	*new_line;
	char	**colors;
	int		count;

	new_line = ft_substr(line, 1, ft_strlen(line) - 1);
	free(line);
	count = ft_count(new_line, ',');
	check_color_count(cub, count, new_line);
	colors = ft_split(new_line, ',');
	if ((ft_tablen(colors) > 3 && colors[3]) || ft_tablen(colors) < 3)
	{
		free_split(colors);
		free(new_line);
		ft_puterror(cub, "Color error! Missing or more than 3 colors.\n");
	}
	if (ft_tablen(colors) == 3)
	{
		if (type == 'F')
			set_color(cub, &cub->map.floor_color, colors, new_line);
		else if (type == 'C')
			set_color(cub, &cub->map.ceiling_color, colors, new_line);
	}
	free_split(colors);
	free(new_line);
}

void	get_map_colors(t_cub *cub)
{
	char	*line;
	int		i;

	i = 0;
	while (cub->map.map_content[i])
	{
		line = ft_strtrim(cub->map.map_content[i], " \t");
		if (line[0] == 'F' || line[0] == 'C')
			process_color_line(cub, line, line[0]);
		else
			free(line);
		i++;
	}
	if ((cub->map.floor_color.r == -1 || cub->map.floor_color.g == -1 \
	|| cub->map.floor_color.b == -1) || (cub->map.ceiling_color.r == -1 \
	|| cub->map.ceiling_color.g == -1 || cub->map.ceiling_color.b == -1))
		ft_puterror(cub, "Color error! Missing floor or ceiling color.\n");
}

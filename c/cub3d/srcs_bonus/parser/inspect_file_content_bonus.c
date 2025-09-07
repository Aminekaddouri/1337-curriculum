/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_file_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:46:00 by akaddour          #+#    #+#             */
/*   Updated: 2024/08/14 17:54:02 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	check_empty_file(t_cub *cub, char **content)
{
	if (content[0] == NULL || content[0][0] == '\0')
	{
		ft_puterror(cub, "Empty file error!\n");
	}
}

void	check_cub_texture(t_cub *cub, char **content)
{
	int		count;
	int		i;
	char	**line;

	count = 0;
	i = 0;
	while (content[i])
	{
		line = ft_split_set(content[i], " \t");
		if (line[0] && (ft_strncmp(line[0], "NO", 2) == 0 \
		|| ft_strncmp(line[0], "SO", 2) == 0 \
		|| ft_strncmp(line[0], "WE", 2) == 0 \
		|| ft_strncmp(line[0], "EA", 2) == 0))
			count++;
		free_split(line);
		i++;
	}
	if (count != 4)
		ft_puterror(cub, "Texture error! Missing one or more textures.\n");
}

void	check_cub_colors(t_cub *cub, char **content)
{
	int		i;
	int		count;
	char	**line;

	i = 0;
	count = 0;
	while (content[i])
	{
		line = ft_split_set(content[i], " \t");
		if (line[0] && (ft_strcmp(line[0], "F") == 0 \
		|| ft_strcmp(line[0], "C") == 0))
			count++;
		free_split(line);
		i++;
	}
	if (count != 2)
		ft_puterror(cub, "Color error! Missing floor or ceiling color.\n");
}

void	check_initial_lines(t_cub *cub, char **content, int *i)
{
	char	**line;

	while (content[*i])
	{
		line = ft_split_set(content[*i], " \t");
		if (is_whitespace_line(content[*i]) || (line[0] \
		&& (ft_strcmp(line[0], "NO") == 0 || ft_strcmp(line[0], "SO") == 0 \
		|| ft_strcmp(line[0], "WE") == 0 || ft_strcmp(line[0], "EA") == 0 \
		|| ft_strcmp(line[0], "F") == 0 || ft_strcmp(line[0], "C") == 0)))
		{
			(*i)++;
		}
		else
		{
			free_split(line);
			break ;
		}
		free_split(line);
	}
	if (!content[*i] || is_whitespace_line(content[*i]))
		ft_puterror(cub, "Map doesn't exist!\n");
}

void	inspect_file_content(t_cub *cub, char **content)
{
	int		i;
	int		j;

	i = 0;
	check_empty_file(cub, content);
	check_cub_texture(cub, content);
	check_cub_colors(cub, content);
	check_initial_lines(cub, content, &i);
	while (content[i])
	{
		j = 0;
		while (content[i][j])
		{
			if (!is_valid_map_char(content[i][j]))
				ft_puterror(cub, "Invalid character in map!\n");
			j++;
		}
		i++;
	}
}

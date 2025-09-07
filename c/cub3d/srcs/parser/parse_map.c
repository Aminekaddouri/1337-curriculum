/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 07:01:07 by akaddour          #+#    #+#             */
/*   Updated: 2024/08/27 14:34:35 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	inspect_file_extension(char *file, char *ext)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		if (file[i] == '/' && file[i + 1] == '.')
			return (1);
		i++;
	}
	i = ft_strlen(file);
	j = ft_strlen(ext);
	if (i <= j)
		return (1);
	while (j >= 0)
	{
		if (file[i] != ext[j])
			return (1);
		i--;
		j--;
	}
	return (0);
}

void	load_map(t_cub *cub)
{
	int		len;
	int		i;
	int		fd;
	char	*str;

	i = 0;
	len = count_nbr_of_lines(cub, cub->map.filename);
	cub->map.map_content = malloc(sizeof(char *) * (len + 1));
	if (!cub->map.map_content)
		ft_puterror(cub, "Malloc Error : load_map\n");
	fd = open(cub->map.filename, O_RDONLY);
	if (fd == -1)
		ft_puterror(cub, "Error opening the file!\n");
	cub->map.map_content[i] = get_next_line(fd);
	while (i < len && cub->map.map_content[i++])
	{
		str = get_next_line(fd);
		cub->map.map_content[i] = ft_strtrim(str, "\n");
		free(str);
	}
	cub->map.map_content[i] = NULL;
	close(fd);
}

void	parse_map(t_cub *cub)
{
	if (inspect_file_extension(cub->map.filename, ".cub"))
		ft_puterror(cub, "The file is not a valid *.cub file.\n");
	load_map(cub);
	inspect_file_content(cub, cub->map.map_content);
	get_map_textures(cub);
	get_map_colors(cub);
	cub->map.height = get_map_len(cub->map.map_content);
	initialize_map(cub);
	validate_map(cub);
	check_map_boundaries(cub);
	get_player_position(cub);
}

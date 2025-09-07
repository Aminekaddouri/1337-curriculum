/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:27:37 by akaddour          #+#    #+#             */
/*   Updated: 2024/08/14 17:54:02 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	count_nbr_of_lines(t_cub *cub, char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_puterror(cub, "Error opening the file!\n");
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

t_bool	is_valid_map_char(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'D'\
	|| c == 'E' || c == 'W' || c == '1' || c == ' ' || c == '\n' || c == '\t');
}

t_bool	is_valid_map_line(const char *line)
{
	while (*line)
	{
		if (*line != '1' && *line != '0' && *line != 'N'
			&& *line != 'S' && *line != 'E' && *line != 'D'
			&& *line != 'W' && !ft_isspace((unsigned char)*line))
		{
			return (false);
		}
		line++;
	}
	return (true);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

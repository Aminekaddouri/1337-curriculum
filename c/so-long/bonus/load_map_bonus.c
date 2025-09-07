/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 00:08:01 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/25 21:57:46 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	map_size(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (i);
}

void	load_map(char *file, t_map *map)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%sso_long: %s: No such file or directory.%s\n",
			RED, file, END);
		exit(EXIT_FAILURE);
	}
	map->row = map_size(fd);
	close(fd);
	map->map = malloc(sizeof(char *) * (map->row + 1));
	if (!map->map)
	{
		ft_printf("%s\n", MALLOC_ERROR);
		exit(EXIT_FAILURE);
	}
	map->map[map->row] = NULL;
	fd = open(file, O_RDONLY);
	while (i < map->row)
		map->map[i++] = get_next_line(fd);
	close(fd);
}

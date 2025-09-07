/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_boundaries.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:59:42 by akaddour          #+#    #+#             */
/*   Updated: 2024/08/27 14:56:40 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_wall_char(char **map_only, int row, int col)
{
	if (map_only[row][col] != '1'
		&& map_only[row][col] != ' ' && map_only[row][col] != '\t')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	delve_deep(char **map, int row, int i)
{
	while (map[row][i])
	{
		if (map[row][i] != '1' && map[row][i] != ' ')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	check_walls(t_cub *cub, int row, int col)
{
	if (row == 0 && is_valid_wall_char(cub->map.map_only, row, col))
		ft_puterror(cub, "Invalid map boundary at the top!\n");
	else if (row == cub->map.height - 1 \
	&& is_valid_wall_char(cub->map.map_only, row, col))
		ft_puterror(cub, "Invalid map boundary at the bottom!\n");
	else if (col == 0 && is_valid_wall_char(cub->map.map_only, row, col))
		ft_puterror(cub, "Invalid map boundary on the left!\n");
	else if (col == ((int)ft_strlen(cub->map.map_only[row]) - 1)
		&& is_valid_wall_char(cub->map.map_only, row, col))
		ft_puterror(cub, "Invalid map boundary on the right!\n");
	else if ((row > 0 && row < cub->map.height - 1)
		&& (col > 0 && col < (int)ft_strlen(cub->map.map_only[row]) - 1))
	{
		if (cub->map.map_only[row][col] == '0'
			&& (cub->map.map_only[row + 1][col] == ' '
			|| cub->map.map_only[row + 1][col] == '\t'
			|| cub->map.map_only[row - 1][col] == ' '
			|| cub->map.map_only[row - 1][col] == '\t'
			|| cub->map.map_only[row][col + 1] == ' '
			|| cub->map.map_only[row][col + 1] == '\t'
			|| cub->map.map_only[row][col - 1] == ' '
			|| cub->map.map_only[row][col - 1] == '\t'))
			ft_puterror(cub, "Invalid map, player can access empty space!.\n");
	}
}

int	check_full_surrounding(char **map, int row)
{
	int	line_1;
	int	line_2;

	line_1 = ft_strlen(map[row]);
	line_2 = 0;
	if (map[row + 1])
		line_2 = ft_strlen(map[row + 1]);
	if (line_1 > line_2 && line_2 > 0)
	{
		if (delve_deep(map, row, line_2))
			return (EXIT_FAILURE);
	}
	else if (line_2 > line_1)
	{
		if (delve_deep(map, row + 1, line_1))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	check_map_boundaries(t_cub *cub)
{
	int	row;
	int	col;

	row = 0;
	while (cub->map.map_only[row])
	{
		col = 0;
		if (check_full_surrounding(cub->map.map_only, row))
			ft_puterror(cub, "Invalid map, map not surrounded by walls!\n");
		while (cub->map.map_only[row][col])
		{
			check_walls(cub, row, col);
			col++;
		}
		row++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:05:29 by akaddour          #+#    #+#             */
/*   Updated: 2024/08/27 15:01:17 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	contains_char(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

void	check_player_surroundings(t_cub *cub, int row, int col)
{
	if (row <= 0 || row >= cub->map.height - 1 \
	|| col <= 0 || col >= cub->map.width - 1)
		ft_puterror(cub, "Player is on the edge of the map!\n");
	if (cub->map.map_only[row - 1][col] == ' ' \
	|| cub->map.map_only[row - 1][col] == '\t' \
	|| cub->map.map_only[row + 1][col] == ' ' \
	|| cub->map.map_only[row + 1][col] == '\t' \
	|| cub->map.map_only[row][col - 1] == ' ' \
	|| cub->map.map_only[row][col - 1] == '\t' \
	|| cub->map.map_only[row][col + 1] == ' ' \
	|| cub->map.map_only[row][col + 1] == '\t')
	{
		ft_puterror(cub, "Player is surrounded by empty space!\n");
	}
}

void	validate_map_helper(t_cub *cub, int *player_count, \
int *player_row, int *player_col)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map.map_only[i])
	{
		j = 0;
		while (cub->map.map_only[i][j])
		{
			if (!contains_char(cub->map.map_only[i][j], " \t01NSEWD"))
			{
				ft_puterror(cub, "Invalid character in map!\n");
			}
			if (contains_char(cub->map.map_only[i][j], "NSEW"))
			{
				(*player_count)++;
				if (*player_count > 1)
					ft_puterror(cub, "Multiple player positions found!\n");
				*player_row = i;
				*player_col = j;
			}
			j++;
		}
		i++;
	}
}

void	validate_map(t_cub *cub)
{
	int		player_count;
	int		player_row;
	int		player_col;

	player_count = 0;
	player_row = -1;
	player_col = -1;
	validate_map_helper(cub, &player_count, &player_row, &player_col);
	if (player_count == 0)
		ft_puterror(cub, "No player position found!");
	check_player_surroundings(cub, player_row, player_col);
}

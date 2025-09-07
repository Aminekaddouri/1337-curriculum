/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:37:22 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/27 15:37:45 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_enemy_positions(t_map *map)
{
	int	i;

	if (map->enemy_positions)
	{
		i = 0;
		while (i < map->enemy_count)
		{
			free(map->enemy_positions[i]);
			i++;
		}
		free(map->enemy_positions);
	}
	if (map->enemy_direction)
		free(map->enemy_direction);
}

void	ft_free(t_map *map, char *str)
{
	int	i;

	i = -1;
	while (++i < map->row)
		free(map->map[i]);
	free(map->map);
	free_enemy_positions(map);
	mlx_destroy_window(map->mlx, map->win);
	free(map->mlx);
	if (ft_strcmp(str, "BRAVO!") == 0)
		ft_printf("%s%s%s\n", GREEN, str, END);
	else if (ft_strcmp(str, "You lost") == 0)
		ft_printf("%s%s%s\n", RED, str, END);
	else if (ft_strcmp(str, "Error\nInvalid image path") == 0)
	{
		ft_printf("%s%s%s\n", RED, str, END);
		exit(EXIT_FAILURE);
	}
	else if (ft_strcmp(str, "mlx_init or mlx_new_window faild!") == 0)
		exit(EXIT_FAILURE);
	else
		ft_printf("%s%s%s\n", RED, str, END);
	exit(0);
}

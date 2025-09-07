/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:37:22 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/27 15:36:10 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_map *map, char *str)
{
	int	i;

	i = -1;
	while (++i < map->row)
		free(map->map[i]);
	free(map->map);
	mlx_destroy_window(map->mlx, map->win);
	free(map->mlx);
	if (ft_strcmp(str, "BRAVO!") == 0)
		ft_printf("%s%s%s\n", GREEN, str, END);
	else if (ft_strcmp(str, "Error\nInvalid image path") == 0)
	{
		ft_printf("%s%s%s\n", RED, str, END);
		exit(EXIT_FAILURE);
	}
	else if (ft_strcmp(str, "mlx_init or mlx_new_window faild!") == 0)
	{
		ft_printf("%s%s%s\n", RED, str, END);
		exit(EXIT_FAILURE);
	}
	else
		ft_printf("%s%s%s\n", RED, str, END);
	exit(0);
}

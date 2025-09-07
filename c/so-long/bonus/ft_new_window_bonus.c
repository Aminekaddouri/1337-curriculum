/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:29:56 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/27 15:38:07 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close(t_map *map)
{
	ft_free(map, "WINDOW CLOSED!");
	return (0);
}

void	ft_new_window(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		ft_free(map, "mlx_init or mlx_new_window faild!");
	map->win = mlx_new_window(map->mlx, map->col * SQUARE,
			map->row * SQUARE, "so_long");
	if (!map->win)
		ft_free(map, "mlx_init or mlx_new_window faild!");
	mlx_hook(map->win, WIN_CLOSE, 0, ft_close, map);
}

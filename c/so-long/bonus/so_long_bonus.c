/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:14:45 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/25 19:57:43 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
	{
		ft_printf("%sError%s\n", RED, END);
		ft_printf("%sUsage: ./so_long <map.ber>\n%s", LIGHT_YELLOW, END);
		exit(EXIT_FAILURE);
	}
	display_banner();
	inspect_map(av[1], &map);
	load_player_frames(&map);
	load_enemy_frames(&map);
	ft_new_window(&map);
	ft_render_images(&map);
	mlx_loop_hook(map.mlx, loop_hook, &map);
	mlx_hook(map.win, 2, 0, *ft_input, &map);
	mlx_loop(map.mlx);
	return (0);
}

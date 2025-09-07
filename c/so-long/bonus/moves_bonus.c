/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 01:47:12 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/25 21:56:30 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_move_up(t_map *map)
{
	if (map->map[map->x - 1][map->y] == 'Y')
		ft_free(map, "You lost");
	if (map->map[map->x - 1][map->y] == '0')
	{
		ft_swap(&map->map[map->x - 1][map->y], &map->map[map->x][map->y]);
		map->x--;
		ft_printf("[%sMOVED UP%s] - [%sCOUNT%s] > %d\n", RED, END, YELLOW, END,
			++map->mv_count);
	}
	else if (map->map[map->x - 1][map->y] == 'C')
	{
		map->collectibles--;
		map->map[map->x][map->y] = '0';
		map->map[map->x - 1][map->y] = 'P';
		map->x--;
	}
	else if (map->map[map->x - 1][map->y] == 'E' && !map->collectibles)
		ft_free(map, "BRAVO!");
}

void	ft_move_down(t_map *map)
{
	if (map->map[map->x + 1][map->y] == 'Y')
		ft_free(map, "You lost");
	if (map->map[map->x + 1][map->y] == '0')
	{
		ft_swap(&map->map[map->x + 1][map->y], &map->map[map->x][map->y]);
		map->x++;
		ft_printf("[%sMOVED DOWN%s] - [%sCOUNT%s] > %d\n", RED, END,
			YELLOW, END, ++map->mv_count);
	}
	else if (map->map[map->x + 1][map->y] == 'C')
	{
		map->collectibles--;
		map->map[map->x][map->y] = '0';
		map->map[map->x + 1][map->y] = 'P';
		map->x++;
	}
	else if (map->map[map->x + 1][map->y] == 'E' && !map->collectibles)
		ft_free(map, "BRAVO!");
}

void	ft_move_left(t_map *map)
{
	map->player_direction = 'L';
	if (map->map[map->x][map->y - 1] == 'Y')
		ft_free(map, "You lost");
	if (map->map[map->x][map->y - 1] == '0')
	{
		ft_swap(&map->map[map->x][map->y - 1], &map->map[map->x][map->y]);
		map->y--;
		ft_printf("[%sMOVED LEFT%s] - [%sCOUNT%s] > %d\n", RED, END,
			YELLOW, END, ++map->mv_count);
	}
	else if (map->map[map->x][map->y - 1] == 'C')
	{
		map->collectibles--;
		map->map[map->x][map->y] = '0';
		map->map[map->x][map->y - 1] = 'P';
		map->y--;
	}
	else if (map->map[map->x][map->y - 1] == 'E' && !map->collectibles)
		ft_free(map, "BRAVO!");
	map->current_frame = (map->current_frame + 1) % 8;
}

void	ft_move_right(t_map *map)
{
	if (map->map[map->x][map->y + 1] == 'Y')
		ft_free(map, "You lost");
	map->player_direction = 'R';
	if (map->map[map->x][map->y + 1] == '0')
	{
		ft_swap(&map->map[map->x][map->y + 1], &map->map[map->x][map->y]);
		map->y++;
		printf("[%sMOVED RIGHT%s] - [%sCOUNT%s] > %d\n", RED, END, YELLOW, END,
			++map->mv_count);
	}
	else if (map->map[map->x][map->y + 1] == 'C')
	{
		map->collectibles--;
		map->map[map->x][map->y] = '0';
		map->map[map->x][map->y + 1] = 'P';
		map->y++;
	}
	else if (map->map[map->x][map->y + 1] == 'E' && !map->collectibles)
		ft_free(map, "BRAVO!");
	map->current_frame = (map->current_frame + 1) % 8;
}

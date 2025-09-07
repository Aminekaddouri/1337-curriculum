/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_rectangular_form_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 00:27:16 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/25 20:25:35 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	invalid_map_form(t_map *map)
{
	ft_printf("%sError%s\n", RED, END);
	ft_printf("%sThe map is not rectangular%s\n", LIGHT_YELLOW, END);
	free_map(map);
	exit(EXIT_FAILURE);
}

int	inspect_rectangular_form(t_map *map)
{
	int	row;
	int	len;
	int	line_len;

	row = 0;
	line_len = ft_strlen(map->map[row]);
	while (map->map[row] != NULL)
	{
		len = ft_strlen(map->map[row]);
		if (line_len != len)
			return (1);
		row++;
	}
	return (0);
}

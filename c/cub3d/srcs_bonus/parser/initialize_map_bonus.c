/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:02:25 by akaddour          #+#    #+#             */
/*   Updated: 2024/08/26 16:52:55 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	get_map_len(char **content)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (content[i])
	{
		if (is_valid_map_line(content[i]))
		{
			len++;
		}
		i++;
	}
	return (len);
}

int	check_new_line(char *str)
{
	return (str[ft_strlen(str) - 1] == '\n');
}

void	initialize_map(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	cub->map.map_only = malloc(sizeof(char *) * (cub->map.height + 1));
	if (!cub->map.map_only)
		ft_puterror(cub, "Malloc Error: get_map\n");
	while (cub->map.map_content[++i])
	{
		if (is_valid_map_line(cub->map.map_content[i])
			&& !is_whitespace_line(cub->map.map_content[i]))
			if (cub->map.width < (int)ft_strlen(cub->map.map_content[i]))
				cub->map.width = (int)ft_strlen(cub->map.map_content[i]);
	}
	i = -1;
	while (cub->map.map_content[++i])
	{
		if (is_valid_map_line(cub->map.map_content[i])
			&& !is_whitespace_line(cub->map.map_content[i]))
			cub->map.map_only[j++] = \
			ft_strndup(cub->map.map_content[i], cub->map.width);
	}
	cub->map.map_only[j] = 0;
	cub->map.height = get_map_len(cub->map.map_only);
}

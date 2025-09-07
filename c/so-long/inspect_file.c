/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:43:48 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/25 22:00:12 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	inspect_file(char *file)
{
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%sError%s\n", RED, END);
		ft_printf("%sso_long: %s: %s%s\n", LIGHT_YELLOW, file, DIR_ERROR, END);
		exit(EXIT_FAILURE);
	}
	str = get_next_line(fd);
	if (str == NULL)
	{
		free(str);
		ft_printf("%sso_long: %s: %s%s\n", RED, file, EXT_ERROR, END);
		exit(EXIT_FAILURE);
	}
	free(str);
	close(fd);
}

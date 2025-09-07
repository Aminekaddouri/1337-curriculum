/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_file_extension.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:52:50 by akaddour          #+#    #+#             */
/*   Updated: 2024/02/26 00:39:11 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_file_extension(char *file)
{
	ft_printf("%sError%s\n", RED, END);
	ft_printf("%sThe file %s is not a valid *.ber file%s\n",
		LIGHT_YELLOW, file, END);
	exit(EXIT_FAILURE);
}

int	inspect_file_extension(char *file, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(file);
	j = ft_strlen(ext);
	if (i < j)
		return (1);
	while (j >= 0)
	{
		if (file[i] != ext[j])
			return (1);
		i--;
		j--;
	}
	return (0);
}

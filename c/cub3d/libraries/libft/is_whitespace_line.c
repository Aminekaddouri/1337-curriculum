/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_whitespace_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:44:12 by akaddour          #+#    #+#             */
/*   Updated: 2024/08/10 12:44:32 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	is_whitespace_line(char *line)
{
	while (*line)
	{
		if (!ft_isspace((unsigned char)*line))
			return (false);
		line++;
	}
	return (true);
}

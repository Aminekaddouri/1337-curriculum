/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:45:21 by akaddour          #+#    #+#             */
/*   Updated: 2023/11/26 09:10:43 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int u)
{
	int	count;

	count = 0;
	if (u >= 10)
	{
		count += print_unsigned(u / 10);
		if (count == -1)
			return (-1);
	}
	count += print_char(u % 10 + '0');
	if (count == -1)
		return (-1);
	return (count);
}

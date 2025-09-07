/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:59:53 by akaddour          #+#    #+#             */
/*   Updated: 2023/11/26 08:58:29 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexadecimal(unsigned int x, const char specifier)
{
	char	string[25];
	char	*base_character;
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (specifier == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	while (x != 0)
	{
		string[i] = base_character [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
	{
		count += print_char(string[i]);
		if (count == -1)
			return (-1);
	}
	return (count);
}

int	print_hexadecimal(unsigned int x, const char specifier)
{
	int		count;

	count = 0;
	if (x == 0)
	{
		count += print_char('0');
		if (count == -1)
			return (-1);
		return (count);
	}
	count += ft_hexadecimal(x, specifier);
	return (count);
}

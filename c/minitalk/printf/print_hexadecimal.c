/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:59:53 by akaddour          #+#    #+#             */
/*   Updated: 2023/11/25 14:57:01 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexadecimal(unsigned int x, const char specifier)
{
	char	string[25];
	char	*base_character;
	int		i;
	int		count;

	count = 0;
	if (specifier == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		count += print_char('0');
		return (count);
	}
	while (x != 0)
	{
		string[i] = base_character[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		count += print_char(string[i]);
	return (count);
}

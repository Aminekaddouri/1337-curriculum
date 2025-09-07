/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:27:10 by akaddour          #+#    #+#             */
/*   Updated: 2023/11/25 12:28:19 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(size_t pointer)
{
	char	string[25];
	int		i;
	int		count;
	char	*base_character;

	base_character = "0123456789abcdef";
	i = 0;
	count = 0;
	count += print_str("0x");
	if (pointer == 0)
		count += print_char('0');
	while (pointer != 0)
	{
		string[i] = base_character[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
	{
		count += print_char(string[i]);
	}
	return (count);
}

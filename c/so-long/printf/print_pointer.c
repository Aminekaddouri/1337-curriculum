/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:27:10 by akaddour          #+#    #+#             */
/*   Updated: 2023/11/26 08:58:15 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_ptr(size_t ptr)
{
	int		i;
	char	string[25];
	int		result;
	char	*base_character;
	int		count;

	i = 0;
	count = 0;
	base_character = "0123456789abcdef";
	while (ptr != 0)
	{
		string[i] = base_character[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
	{
		result = print_char(string[i]);
		if (result == -1)
			return (-1);
		count += result;
	}
	return (count);
}

int	print_pointer(size_t pointer)
{
	int		count;
	int		result;

	count = print_str("0x");
	if (count == -1)
		return (-1);
	if (pointer == 0)
	{
		result = print_char('0');
		if (result == -1)
			return (-1);
		count += result;
	}
	else
		count += print_ptr(pointer);
	return (count);
}

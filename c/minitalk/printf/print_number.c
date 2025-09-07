/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:52:17 by akaddour          #+#    #+#             */
/*   Updated: 2023/11/25 15:12:46 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(int number)
{
	int	count;

	count = 0;
	if (number == -2147483648)
	{
		count += print_str("-2147483648");
		return (count);
	}
	if (number < 0)
	{
		count += print_char('-');
		count += print_number(number * -1);
	}
	else
	{
		if (number > 9)
			count += print_number(number / 10);
		count += print_char(number % 10 + '0');
	}
	return (count);
}

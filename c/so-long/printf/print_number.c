/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:52:17 by akaddour          #+#    #+#             */
/*   Updated: 2023/11/26 08:58:38 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_number(int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_number(n / 10);
		if (count == -1)
			return (-1);
	}
	count += print_char(n % 10 + '0');
	return (count);
}

int	print_number(int number)
{
	int	count;

	count = 0;
	if (number == -2147483648)
	{
		count = print_str("-2147483648");
		if (count == -1)
			return (-1);
		return (count);
	}
	if (number < 0)
	{
		count += print_char('-');
		if (count == -1)
			return (-1);
		count += print_number(number * -1);
	}
	else
		count += ft_number(number);
	return (count);
}

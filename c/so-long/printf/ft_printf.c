/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:02:56 by akaddour          #+#    #+#             */
/*   Updated: 2023/11/26 09:07:42 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	if (write(1, &c, 1) == 1)
		return (1);
	return (-1);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i] != '\0')
	{
		if (print_char(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

static int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		count += print_pointer(va_arg(ap, size_t));
	else if (specifier == 'd' || specifier == 'i')
		count += print_number(va_arg(ap, int));
	else if (specifier == 'u')
		count += print_unsigned(va_arg(ap, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += print_hexadecimal(va_arg(ap, unsigned int), specifier);
	else if (specifier == '%')
		count += print_char('%');
	return (count);
}

static int	ft_helper(const char *format, va_list ap)
{
	int		count;
	int		res;

	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(format + 1) == '\0')
				return (count);
			res = print_format(*((format++) + 1), ap);
			if (res == -1)
				return (-1);
			count += res;
		}
		else
		{
			if (print_char(*format) == -1)
				return (-1);
			count++;
		}
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	count += ft_helper(format, ap);
	va_end(ap);
	return (count);
}

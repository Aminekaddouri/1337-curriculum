/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:55:56 by akaddour          #+#    #+#             */
/*   Updated: 2023/11/26 10:15:19 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		print_char(int c);
int		print_str(char *str);
int		print_pointer(size_t pointer);
int		print_number(int number);
int		print_unsigned(unsigned int u);
int		print_hexadecimal(unsigned int x, const char specifier);

#endif
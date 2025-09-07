/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:56:47 by akaddour          #+#    #+#             */
/*   Updated: 2023/12/20 09:44:31 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ps_strlen(char **av)
{
	int	i;

	i = 0;
	while (*av)
	{
		av++;
		i++;
	}
	return (i);
}

long long	parse_number(char *str, unsigned int i, int *stack)
{
	long long	number;

	number = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_detected(stack);
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	return (number);
}

int	ps_atoi(char *str, int *stack)
{
	unsigned int		i;
	int					sign;
	long long			number;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (ft_strlen(str + i) > 10)
		error_detected(stack);
	if (str[i] < '0' || str[i] > '9')
		error_detected(stack);
	number = parse_number(str, i, stack);
	if ((number * sign < INT_MIN) || (number * sign > INT_MAX))
		error_detected(stack);
	return (number * sign);
}

void	check_doubles(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack[i] == stack[j])
				error_detected(stack);
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	check_sorted(int *stack, int size, int order)
{
	int	i;

	if (order == 0)
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] > stack[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] < stack[i])
				return (0);
			i++;
		}
		return (1);
	}
}

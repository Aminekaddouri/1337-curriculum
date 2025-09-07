/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:46:14 by akaddour          #+#    #+#             */
/*   Updated: 2023/12/20 12:33:39 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_detected(int *stack)
{
	free(stack);
	write(2, "Error\n", 6);
	exit (1);
}

void	push_swap(char **av)
{
	t_stack	stack;
	int		size;
	int		i;

	i = -1;
	size = ps_strlen(av);
	stack.a = malloc(size * sizeof(int));
	if (!stack.a)
		return ;
	stack.size_a = size;
	stack.b = malloc(size * sizeof(int));
	if (!stack.b)
	{
		free(stack.a);
		return ;
	}
	stack.size_b = 0;
	while (++i < size)
		stack.a[i] = ps_atoi(av[i], stack.a);
	check_doubles(stack.a, size);
	sort(&stack, size);
	free(stack.a);
	free(stack.b);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, ' ');
		if (*av == NULL)
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		push_swap(av);
		return (0);
	}
	return (0);
}

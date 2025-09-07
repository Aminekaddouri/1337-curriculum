/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:37:40 by akaddour          #+#    #+#             */
/*   Updated: 2023/12/20 22:11:04 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1)
		return ;
	i = 0;
	tmp = stack->a[i];
	i++;
	while (i < stack->size_a)
	{
		stack->a[i - 1] = stack->a[i];
		i++;
	}
	stack->a[i - 1] = tmp;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->size_b == 0 || stack->size_a == 1)
		return ;
	i = 0;
	tmp = stack->b[i];
	i++;
	while (i < stack->size_b)
	{
		stack->b[i - 1] = stack->b[i];
		i++;
	}
	stack->b[i - 1] = tmp;
	write(1, "rb\n", 3);
}

void	rotate_r(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
	write(1, "rr\n", 3);
}

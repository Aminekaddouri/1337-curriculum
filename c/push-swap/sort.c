/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:19:43 by akaddour          #+#    #+#             */
/*   Updated: 2023/12/20 22:15:08 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	temporary_sort(int *stack_temporaire, int size)
{
	int	i;
	int	j;
	int	temporaire;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack_temporaire[i] > stack_temporaire[j])
			{
				temporaire = stack_temporaire[i];
				stack_temporaire[i] = stack_temporaire[j];
				stack_temporaire[j] = temporaire;
			}
			j++;
		}
		i++;
	}
}

void	three_numbers_sort(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[0] < stack->a[2]
		&& stack->a[1] < stack->a[2])
		swap_a(stack);
	if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2]
		&& stack->a[1] > stack->a[2])
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2]
		&& stack->a[1] < stack->a[2])
		rotate_a(stack);
	if (stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2]
		&& stack->a[1] > stack->a[2])
	{
		swap_a(stack);
		rotate_a(stack);
	}
	if (stack->a[0] < stack->a[1] && stack->a[0] > stack->a[2]
		&& stack->a[1] > stack->a[2])
		reverse_rotate_a(stack);
}

int	sort(t_stack *stack, int size)
{
	if (check_sorted(stack->a, stack->size_a, 0) == 0)
	{
		if (size == 2)
			swap_a(stack);
		else if (size == 3)
			three_numbers_sort(stack);
		else
			quicksort_stack_a(stack, size, 0);
	}
	return (0);
}

int	ft_push(t_stack *stack, int len, int push)
{
	if (push == 0)
		push_b(stack);
	else
		push_a(stack);
	len--;
	return (len);
}

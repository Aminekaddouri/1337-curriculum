/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:36:06 by akaddour          #+#    #+#             */
/*   Updated: 2023/12/20 22:09:13 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

void	push_swap(char **av);
int		ps_strlen(char **av);
void	error_detected(int *stack);
int		ps_atoi(char *str, int *stack);
void	check_doubles(int *stack, int size);

int		check_sorted(int *stack, int size, int order);
int		sort(t_stack *stack, int size);
void	three_numbers_sort(t_stack *stack);
void	temporary_sort(int *stack_temporaire, int size);

int		quicksort_stack_a(t_stack *stack, int len, int count_r);
void	sort_three_stack_a(t_stack *stack, int len);
int		quicksort_stack_b(t_stack *stack, int len, int count_r);
int		sort_three_stack_b(t_stack *stack, int len);
int		ft_push(t_stack *stack, int len, int push);

void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_r(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_r(t_stack *stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_s(t_stack *stack);

#endif
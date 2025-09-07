/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 01:17:00 by akaddour          #+#    #+#             */
/*   Updated: 2024/08/14 15:31:54 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t size)
{
	unsigned char	*char_ptr;
	size_t			i;

	i = 0;
	char_ptr = (unsigned char *)ptr;
	while (i < size)
	{
		char_ptr[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (n + 1));
	if (result == NULL)
		return (NULL);
	ft_bzero(result, n);
	i = 0;
	while (s1[i] && i < n)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

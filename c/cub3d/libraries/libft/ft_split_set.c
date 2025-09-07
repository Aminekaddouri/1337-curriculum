/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:51:55 by akaddour          #+#    #+#             */
/*   Updated: 2024/08/10 13:14:26 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	is_delimiter(char c, const char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (true);
		delim++;
	}
	return (false);
}

static char	**ft_freeup(char **res)
{
	int	i;

	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static char	**ft_allocate(char **res, char const *s, const char *delim)
{
	char		**tab;
	char const	*tmp;

	tab = res;
	tmp = s;
	while (*tmp)
	{
		while (is_delimiter(*s, delim))
			++s;
		tmp = s;
		while (*tmp && !is_delimiter(*tmp, delim))
			++tmp;
		if (tmp > s)
		{
			*tab = ft_strndup(s, tmp - s);
			if (!*tab)
				return (ft_freeup(res));
			s = tmp;
			++tab;
		}
	}
	*tab = NULL;
	return (res);
}

static int	word_count(char const *s, const char *delim)
{
	int	size;

	size = 0;
	while (*s)
	{
		while (is_delimiter(*s, delim))
			++s;
		if (*s)
			++size;
		while (*s && !is_delimiter(*s, delim))
			++s;
	}
	return (size);
}

char	**ft_split_set(char const *s, const char *delim)
{
	char	**res;
	int		size;

	if (s == NULL || delim == NULL)
		return (NULL);
	size = word_count(s, delim);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (res == NULL)
		return (NULL);
	res = ft_allocate(res, s, delim);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:12:35 by akaddour          #+#    #+#             */
/*   Updated: 2024/08/11 16:55:15 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef enum e_bool
{
	true = 1,
	false = 0,
}	t_bool;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *str);
int		ft_isspace(char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	**ft_split_2(char const *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strndup(const char *s1, size_t n);
int		ft_strcmp(char *s1, char *s2);
int		ft_isspace(char c);
void	ft_atol(const char *str, int *overflow);
char	**ft_split_set(char const *s, const char *delim);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strtrim(char const *s1, char const *set);
t_bool	is_whitespace_line(char *line);
int		ft_tablen(char **tab);
int		ft_count(char *str, char c);

#endif
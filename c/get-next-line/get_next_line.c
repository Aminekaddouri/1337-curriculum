/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:51:35 by akaddour          #+#    #+#             */
/*   Updated: 2023/11/30 18:33:39 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *buffer, char *line)
{
	ssize_t	read_count;

	read_count = 1;
	while (read_count)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(buffer);
			return (NULL);
		}
		else if (read_count == 0)
			break ;
		buffer[read_count] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (line);
}

static char	*ft_get_next_line(char *line)
{
	size_t	count;
	char	*str;

	count = 0;
	if (line[count] == '\0')
		return (NULL);
	while (line[count] != '\0' && line[count] != '\n')
		count++;
	str = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*str == '\0')
	{
		free(str);
		return (NULL);
	}
	line[count + 1] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*next_line = NULL;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647
		|| read(fd, &buffer, 0) < 0)
	{
		free(next_line);
		next_line = NULL;
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_read_line(fd, buffer, next_line);
	free(buffer);
	if (!line)
		return (NULL);
	next_line = ft_get_next_line(line);
	return (line);
}

// int main()
// {
// 	int fd = open("lorem.txt", O_RDONLY);
// 	char *str;
// 	while ((str = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", str);
// 	}
// 	close(fd);
// }
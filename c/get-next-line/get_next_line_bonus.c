/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:35:31 by akaddour          #+#    #+#             */
/*   Updated: 2023/11/30 18:33:56 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_line(int fd, char *buffer, char *line)
{
	ssize_t		read_count;

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
	char	*str;
	int		count;

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
	static char	*next_line[OPEN_MAX];
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647
		|| read(fd, &buffer, 0) < 0)
	{
		free(next_line[fd]);
		next_line[fd] = NULL;
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_read_line(fd, buffer, next_line[fd]);
	free(buffer);
	if (!line)
		return (NULL);
	next_line[fd] = ft_get_next_line(line);
	return (line);
}

// int main()
// {
// 	int fd = open("lorem.txt", O_RDONLY);
// 	int fd2 = open("text.text", O_RDONLY);
// 	int fd3 = open("test.txt", O_RDONLY);
// 	char *str;
// 	while ((str = get_next_line(fd))!= '\0')
// 	{
// 		printf("%s", str);
// 	}
// 	printf("\n==============================================\n");
// 	while ((str = get_next_line(fd2))!= '\0')
// 	{
// 		printf("%s", str);
// 	}
// 	printf("\n==============================================\n");
// 	while ((str = get_next_line(fd3))!= '\0')
// 	{
// 		printf("%s", str);
// 	}
// 	close(fd);
// }
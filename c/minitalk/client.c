/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:34:09 by akaddour          #+#    #+#             */
/*   Updated: 2024/01/21 13:11:15 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x80 >> bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

void	send_message(char *message, int pid)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(message);
	i = 0;
	while (i < len)
	{
		send_signals(message[i], pid);
		usleep(500);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("client: invalid arguments\n");
		ft_printf("\tcorrect format [%s SERVER_PID MESSAGE]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_message(argv[2], pid);
	return (0);
}

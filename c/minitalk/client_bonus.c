/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:47:40 by akaddour          #+#    #+#             */
/*   Updated: 2024/01/21 01:24:46 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	confirm_msg(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_printf("message recieved\n");
	}
}

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
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("client: invalid arguments\n");
		ft_printf("\tcorrect format [%s SERVER_PID MESSAGE]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_message(argv[2], pid);
	signal(SIGUSR2, confirm_msg);
	send_signals('\0', pid);
	return (0);
}

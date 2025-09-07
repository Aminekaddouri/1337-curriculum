/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:34:15 by akaddour          #+#    #+#             */
/*   Updated: 2024/01/21 13:11:08 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// server.c
void	handler_sigusr(int signum)
{
	static char	c = 0xFF;
	static int	bits = 0;

	if (signum == SIGUSR1)
	{
		c |= (0x80 >> bits);
	}
	else if (signum == SIGUSR2)
	{
		c ^= (0x80 >> bits);
	}
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", c);
		bits = 0;
		c = 0xFF;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	while (1)
		pause();
	return (0);
}

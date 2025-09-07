/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:02:59 by akaddour          #+#    #+#             */
/*   Updated: 2024/01/15 00:18:52 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler_sigusr(int sig, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bits;

	(void)context;
	if (sig == SIGUSR1)
	{
		c |= (0x80 >> bits);
	}
	else if (sig == SIGUSR2)
	{
		c ^= (0x80 >> bits);
	}
	bits++;
	if (bits == 8)
	{
		if (c == 0)
			kill(info->si_pid, SIGUSR2);
		ft_printf("%c", c);
		bits = 0;
		c = 0xFF;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	act.sa_sigaction = handler_sigusr;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}

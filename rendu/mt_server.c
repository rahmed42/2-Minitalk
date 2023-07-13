/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:00:00 by rahmed            #+#    #+#             */
/*   Updated: 2021/11/22 21:47:06 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;
	sigset_t			set;

	pid = show_pid();
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	action.sa_handler = server_handler;
	action.sa_mask = set;
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}

int	show_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID = %d\n", pid);
	return (pid);
}

void	server_handler(int signo)
{
	static int	b = 0;
	static char	c = 0;

	if (signo == SIGUSR2)
		c |= (1 << b++);
	else if (signo == SIGUSR1)
		c &= ~(1 << b++);
	if (b >= 8)
	{
		b = 0;
		write(1, &c, 1);
		c = 0;
	}
}

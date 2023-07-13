/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:00:00 by rahmed            #+#    #+#             */
/*   Updated: 2021/11/23 16:53:56 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
		err_args();
	else
		send_char_to_binary(ft_atoi(argv[1]), argv[2]);
	return (0);
}

void	err_args(void)
{
	ft_printf("ERROR ARGS : ./mt_client <Server_PID> <Message to send>\n");
	exit(EXIT_FAILURE);
}

void	send_char_to_binary(int pid, char *str)
{
	int	b;

	while (*str)
	{
		b = 0;
		while (b < 8)
		{
			if (*str & (1 << b))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			++b;
			usleep(500);
		}
		++str;
	}
}

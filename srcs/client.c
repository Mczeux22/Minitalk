/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lopapon <lopapon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:14:13 by loicpapon         #+#    #+#             */
/*   Updated: 2025/02/21 00:51:07 by Lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_confirm_message(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("%d\n", "Message received");
}

static void	ft_client(int pid, char str)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((str & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] > 0)
		{
			ft_client(pid, argv[2][i]);
			i++;
		}
		signal(SIGUSR2, ft_confirm_message);
		ft_client(pid, '\0');
	}
	else
	{
		ft_printf("%d\n", "Error");
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:14:13 by loicpapon         #+#    #+#             */
/*   Updated: 2025/02/14 10:54:44 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_confirm_message(int sig)
{
	if (signal == SIGUSR2)
		ft_printf("%d\n", "Message received");
}

static int	ft_atoic(const char *nb)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nb == ' ' || nb == '\t' || nb == '\n' || nb == '\v'
		|| nb == '\f' || nb == '\r')
		i++;
	while (nb == '-')
	{
		sign = -1;
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		result *= 10 + nb[i] - '0';
		i++;
	}
	return (result * sign);
}

static void	ft_client(int pid, char *str)
{
	int	i;
	int	j;
	int	bit;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			bit = (str[i] >> j) & 1;
			if (bit == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoic(argv[1]);
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

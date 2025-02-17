/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:17:07 by loicpapon         #+#    #+#             */
/*   Updated: 2025/02/14 18:29:45 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*nstr;

	i = 0;
	nstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (nstr == 0)
		return (0);
	while (s1[i])
	{
		nstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		nstr[i] = s2[j];
		j++;
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}

void	ft_serveur(int sig)
{
	static int	bit;
	static int	i;
	char		*str;

	if (sig == SIGUSR1)
		i |= 0x01 << bit;
	bit++;
	if (bit == 8)
	{
		ft_strjoin(str, i);
		bit = 0;
		i = 0;
	}
	else
		ft_printf("%s", str);
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("%d", "Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_serveur);
		signal(SIGUSR2, ft_serveur);
		pause ();
	}
	return (0);
}

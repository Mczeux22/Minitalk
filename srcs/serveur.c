/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lopapon <lopapon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:17:07 by loicpapon         #+#    #+#             */
/*   Updated: 2025/02/26 18:44:13 by Lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*ft_strjoine(char *s1, char s2)
{
	int		i;
	char	*nstr;

	i = 0;
	nstr = (char *)malloc(ft_strlen(s1) + 2);
	if (nstr == 0)
		return (0);
	while (s1 && s1[i])
	{
		nstr[i] = s1[i];
		i++;
	}
	nstr[i++] = s2;
	nstr[i] = '\0';
	free(s1);
	return (nstr);
}

void	ft_serveur(int sig)
{
	static int	bit;
	static int	i;
	static char	*str;

	if (sig == SIGUSR1)
		i |= 0x01 << bit;
	bit++;
	if (bit == 8)
	{
		str = ft_strjoine(str, i);
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

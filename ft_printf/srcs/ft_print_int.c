/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:46:14 by loicpapon         #+#    #+#             */
/*   Updated: 2024/12/01 17:10:35 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	ft_print_int(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		(*len) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_print_char('-', len);
		ft_print_int(n * -1, len);
	}
	else
	{
		if (n > 9)
			ft_print_int(n / 10, len);
		ft_print_char(n % 10 + '0', len);
	}
}

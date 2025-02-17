/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:44:02 by loicpapon         #+#    #+#             */
/*   Updated: 2025/02/14 18:55:06 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_str(char *str, int *len)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		(*len) += 6;
		return ;
	}
	while (str[i])
	{
		ft_print_char(str[i], len);
		i++;
	}
}

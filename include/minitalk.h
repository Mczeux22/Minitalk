/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:06:00 by loicpapon         #+#    #+#             */
/*   Updated: 2025/02/14 18:42:48 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// Fonction principale de printf
int		ft_printf(const char *str, ...);

// Fonctions pour chaque conversion
void	ft_print_char(char c, int *len);
void	ft_print_hexa(unsigned int hexa, int *len, char format);
void	ft_print_int(int n, int *len);
void	ft_print_unsigned(unsigned int nb, int *len);
void	ft_print_str(char *str, int *len);
void	ft_print_percent(void);
void	ft_pointeur(void *arg, int *len);
int		ft_putstr(char *str);

#endif
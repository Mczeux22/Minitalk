# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 10:20:23 by loicpapon         #+#    #+#              #
#    Updated: 2025/02/14 19:02:18 by loicpapon        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF	=	ft_printf/ft_print_char.c \
			ft_printf/ft_print_hex.c \
			ft_printf/ft_print_int.c \
			ft_printf/ft_print_percent.c \
			ft_printf/ft_print_ptr.c \
			ft_printf/ft_print_str.c \
			ft_printf/ft_print_unsigned_int.c \
			ft_printf/ft_printf.c \

SRCC		= srcs/client.c
SRCS		= srcs/serveur.c
OBJS		= ${SRCS:.c=.o}
OBJC		= ${SRCC:.c=.o}
PRINTFF		= ${PRINTF:.c=.o}
NAMEC		= client
NAMES		= serveur
INLUDE		= -I include
CC			= cc
CFLAGS		= -Wall -Werror -Wextra


all:		$(NAMEC) $(NAMES) $(PRINTFF)

$(NAMEC) : $(OBJC)
		$(CC) $(CFLAGS) $(INCLUDE) $(OBJC) $(NAMEC)
$(NAMES) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(NAMES)
$(PRINTFF) : $(PRINTF)
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(PRINTF)



clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAMES} ${NAMEC} ${PRINTFF}

re:			fclean all

.PHONY:		all clean fclean re bonus
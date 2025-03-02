# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Lopapon <lopapon@student.42perpignan.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 00:52:46 by Lopapon           #+#    #+#              #
#    Updated: 2025/02/26 18:37:20 by Lopapon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = srcs/serveur.c srcs/client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude

all: serveur client

serveur: srcs/serveur.o libft/libft.a
	$(CC) -o $@ srcs/serveur.o -Llibft -lft

client: srcs/client.o libft/libft.a
	$(CC) -o $@ srcs/client.o -Llibft -lft

srcs/%.o: srcs/%.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	rm -rf objs
	
fclean: clean
	rm -f serveur client libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re
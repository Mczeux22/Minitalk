# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 19:15:20 by loicpapon         #+#    #+#              #
#    Updated: 2025/01/24 17:38:51 by loicpapon        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors for output
RED    = $(shell printf "\33[31m")
GREEN  = $(shell printf "\33[32m")
RESET  = $(shell printf "\33[0m")

# Name of the final library
NAME = libftprintf.a

# Flags and compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Paths
SRCDIR = srcs
OBJDIR = objs
INCDIR = includes
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

# Source and object files
SRCS = srcs/ft_print_char.c srcs/ft_print_hex.c srcs/ft_print_int.c srcs/ft_print_percent.c srcs/ft_print_ptr.c srcs/ft_print_str.c srcs/ft_print_unsigned_int.c \
srcs/ft_printf.c
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)libftprintf.a created successfully!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I $(INCDIR) -I $(LIBFTDIR) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFTDIR)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean
	@echo "$(RED)Cleaned all objects!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean
	@echo "$(RED)Fully cleaned the project!$(RESET)"

re: fclean all

.PHONY: all clean fclean re

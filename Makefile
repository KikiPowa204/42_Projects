# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knajmech <knajmech@student.42vienna.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 10:12:48 by knajmech          #+#    #+#              #
#    Updated: 2025/10/24 10:38:39 by knajmech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OBJ = $(SRCS:.c=.o)
SRCS = ft_printf.c \
LIBFT_P = ./libft
LIBFT = $(LIBFT_P)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_P)
	ar rcs $@ $? $(LIBFT)

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm $(OBJ)

fclean : clean
	rm -f $(NAME)

re :
	fclean all

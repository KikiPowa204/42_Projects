# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knajmech <knajmech@student.42vienna.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 10:12:48 by knajmech          #+#    #+#              #
#    Updated: 2025/10/24 12:51:14 by knajmech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OBJ = $(SRCS:.c=.o)
SRCS = ft_printf.c \
	   ft_putnbr_base.c
LIBFT_P = libft

all: $(NAME)

$(NAME): libft $(OBJ)
	@make -C $(LIBFT_P)
	@cp $(LIBFT_P)/libft.a $(NAME)
	ar rcs $(NAME) $(LIBFT_P)/libft.a $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	@make -C $(LIBFT_P) clean

fclean : clean
	rm -f $(NAME)
	@make -C $(LIBFT_P) fclean

re :
	fclean all

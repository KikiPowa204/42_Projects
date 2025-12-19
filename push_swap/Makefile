# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knajmech <knajmech@student.42vienna.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 08:06:37 by knajmech          #+#    #+#              #
#    Updated: 2025/12/19 08:34:21 by knajmech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
OBJ = $(SRC:.c=.o)
SRC = *c
PATH_l = libft
PATH_p = printf

all: $(NAME)
$(NAME): $(PATH_l) $(PATH_p) $(OBJ)
	@make -C $(PATH_p)
	@cp $(PATH_l)/libft.a $(NAME)
	@make -C $(PATH_l)
	@cp $(PATH_p)/libftprintf.a $(NAME)
	ar rcs $(NAME) $(LIBFT_p)/libft.a $(LIBFT_l)/libftprintf.a $(OBJ)

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	@make -C $(PATH_l) clean
	@make -C $(PATH_p) clean

fclean : clean
	rm -f $(NAME)
	@rm -f $(PATH_l)/libft.a
	@rm -f $(PATH_p)/libftprintf.a

re : fclean all

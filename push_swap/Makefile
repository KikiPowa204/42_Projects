# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 08:06:37 by knajmech          #+#    #+#              #
#    Updated: 2026/01/09 09:46:53 by knajmech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = 	stack_manager.c\
		error_handling.c\
		push_swap.c\
		snorting_department.c\
		first_seven.c\
		checking_department.c\
		array_hq.c\
		create_order.c\
		rotation_nation.c\
		swap_cops.c\
		push_town.c

OBJ = $(SRC:.c=.o)

LIBFT = printf/libft/libft.a
PRINTF = printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C printf/libft bonus
	@make -C printf
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C printf/libft clean
	@make -C printf clean

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
	@make -C printf/libft fclean
	@make -C printf fclean

re: fclean all

.PHONY: all clean fclean re
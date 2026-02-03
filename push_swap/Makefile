# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knajmech <knajmech@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 08:06:37 by knajmech          #+#    #+#              #
#    Updated: 2026/02/02 11:18:20 by knajmech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMEB = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
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
		push_town.c\
		accounting.c\
		clear_mem.c\

SRCB =	./bonus/checker.c\
		./bonus/checker_utils.c\
		./bonus/get_next_line.c\
		./bonus/ft_atoi_b.c\
		./bonus/rotation_nation_bonus.c\
		./bonus/swap_cops_bonus.c\
		./bonus/push_town_bonus.c\
		clear_mem.c\

OBJ = $(SRC:.c=.o)
OBJSB = $(SRCB:.c=.o)

LIBFT = printf/libft/libft.a
PRINTF = printf/libftprintf.a

all: $(NAME)

bonus :.bonus all

.bonus : $(OBJSB)
	@make -C printf/libft bonus
	@make -C printf
	$(CC) $(CFLAGS) $(OBJSB) $(PRINTF) $(LIBFT) -o $(NAMEB)
	@touch .bonus

$(NAME): $(OBJ)
	@make -C printf/libft bonus
	@make -C printf
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)

#%.o:%.c push_swap.h
#	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJSB) .bonus
	@make -C printf/libft clean
	@make -C printf clean

fclean:
	rm -f $(OBJ) $(OBJSB) .bonus
	rm -f $(NAME)
	rm -f $(NAMEB)
	@make -C printf/libft fclean
	@make -C printf fclean

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re bonus debug
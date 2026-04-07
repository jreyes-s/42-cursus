# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/13 18:28:11 by tide-oli          #+#    #+#              #
#    Updated: 2026/04/06 06:52:31 by jreyes-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c\
		rotate.c\
		reverse_rotate.c\
		swap.c\
		push.c\
		disorder_index.c\
		ft_atoi_long.c\
		simple_algorithm.c\
		medium_algorithm.c\
		complex_algorithm.c\
		cleanup_stack.c\
		assignment_indices.c\
		is_sorted.c\
		get_sorted.c\
		bubble_sort.c\
		main.c\
		ft_isnumber.c\

OBJ = $(SRC:.c=.o)
INCLUDES = -I.

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re

# ***************************************************************************: #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichebota <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/06 16:10:07 by ichebota          #+#    #+#              #
#    Updated: 2017/04/13 20:32:41 by ichebota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
HEADER = filler.h
SRC = filler.c game.c get_next_line.c manhattan.c map00.c read.c utilities.c
FLAGS = -Wall -Wextra -Werror
CC = gcc
LIBFT	= libft/libft.a

all: $(NAME)

$(NAME): $(SRC)
	@make -C ./libft
	@make clean -C ./libft
	@$(CC) $(FLAGS) -c $(SRC) 
	@$(CC) -o $(NAME) $(SRC) $(LIBFT)
	make clean
clean:
		@rm -f *.o
fclean:
		make clean
		@rm -f $(NAME)
re:
		@make fclean 
		@make all
		@make clean

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

NAME = liba.a
HEADER = filler.h
SRC = *.c libft/*.c
OBJ = *.o
FLAGS = -c -g
CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
	$(CC) filler.c -o filler -L. -la
clean:
		@rm -f $(OBJ)
fclean:
		make clean
		@rm -f $(NAME)
re:
		make fclean 
		make all
		@ar rc $(NAME) $(OBJ)

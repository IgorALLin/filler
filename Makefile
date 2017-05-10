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

NAME = libfiller.a
HEADER = filler.h
SRC = filler.c ft_atoi.c ft_isascii.c ft_isdigit.c ft_memalloc.c ft_memset.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strcat.c ft_strchr.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strnew.c ft_strsplit.c ft_strstr.c ft_strsub.c game.c get_next_line.c manhattan.c map00.c read.c utilities.c
OBJ = $(SRC:.c=.o)
FLAGS = -c
CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)
	$(CC) filler.c -o filler -L. -lfiller
clean:
		@rm -f $(OBJ)
fclean:
		make clean
		@rm -f $(NAME)
re:
		make fclean 
		make all
		@ar rc $(NAME) $(OBJ)
		make clean

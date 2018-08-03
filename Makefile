# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbohatch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 14:29:58 by dbohatch          #+#    #+#              #
#    Updated: 2017/12/14 14:59:52 by dbohatch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCS =	checking.c \
		count_tetriminos.c \
		cut_tetriminos.c \
		ft_error.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		main.c \
		passing.c \
		read.c \
		strdup_except_symb.c \
		validate.c \

HEADER = fillit.h
 
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(SRCS) -o $(NAME)

clean:
	/bin/rm -f *.o
	/bin/rm -f *.gch

fclean: clean
	/bin/rm -f $(NAME)
	
re: fclean all

%.o: %.c
	gcc $(FLAGS) -I $(HEADER) -c $< -o $@

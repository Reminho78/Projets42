# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 18:07:17 by rcorroy           #+#    #+#              #
#    Updated: 2024/03/04 16:10:00 by rcorroy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEPS	=	printf.h
CC		=	cc
RM		=	rm -f
FLAGS	=	-Wall -Wextra -Werror
LIBC	=	ar rcs
NAME	=	libftprintf.a

OBJS 	= 	ft_printf.o\
			manips_fonctions.o\
			ft_putnbr_base.o\
			used_functions.o

all: 		${NAME}

${NAME}: 	${OBJS}
			${LIBC} ${NAME} ${OBJS}

clean:
			$(RM) $(OBJS)
fclean:		clean
			$(RM) $(NAME)

re:			fclean	all

.PHONY:		all clean re fclean

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(FLAGS)

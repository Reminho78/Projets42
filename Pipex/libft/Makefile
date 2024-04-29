# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 13:51:51 by rcorroy           #+#    #+#              #
#    Updated: 2024/04/10 14:15:43 by rcorroy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEPS			= libft.h
LIBC			= ar rcs
CC				= cc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror
NAME			= libft.a

OBJS = ft_atoi.o ft_memset.o ft_memcpy.o ft_strrchr.o ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o\
	ft_strmapi.o ft_striteri.o ft_itoa.o ft_split.o ft_strtrim.o ft_strjoin.o ft_calloc.o ft_strdup.o ft_memmove.o ft_isalpha.o ft_isdigit.o ft_strlen.o ft_bzero.o ft_strlcpy.o\
	ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_putchar_fd.o ft_substr.o ft_strlcat.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_strchr.o ft_printf.o\
	ft_putnbr_base.o

all:			$(NAME)

${NAME}: 		${OBJS}
				${LIBC} ${NAME} ${OBJS}

OBJSBONUS = ft_lstmap_bonus.o ft_lstiter_bonus.o ft_lstclear_bonus.o ft_lstdelone_bonus.o ft_lsadd_back_bonus.o ft_last_bonus.o ft_lstadd_front_bonus.o ft_lstnew_bonus.o ft_lstsize_bonus.o
				
bonus: $(OBJSBONUS)
		${LIBC} $(NAME) $(OBJSBONUS)
clean:
				$(RM) $(OBJS)
fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean re fclean bonus

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(FLAGS)
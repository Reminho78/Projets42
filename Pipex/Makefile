# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 13:11:20 by remidubenar       #+#    #+#              #
#    Updated: 2024/07/15 13:11:23 by remidubenar      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS = pipex_bonus
CC = gcc
SRCS = pipex.c pipex_utils.c
BONUS_SRCS = pipex_bonus.c pipex_bonus_utils.c pipex_utils.c
CFLAGS = -Wall -Wextra -Werror -g
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
MY_LIB = ./libft/libft.a
MY_LIBDIR = ./libft/

all: $(NAME)

$(MY_LIB):
	@make -C $(MY_LIBDIR)

$(NAME): $(MY_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MY_LIB) -g -o $(NAME)

bonus: $(MY_LIB) $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(MY_LIB) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@make -C $(MY_LIBDIR) clean

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@make -C $(MY_LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
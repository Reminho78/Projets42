# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 14:59:00 by rcorroy           #+#    #+#              #
#    Updated: 2024/09/03 16:58:02 by rcorroy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
BONUS = philo_bonus
CC = gcc
SRCS = philo.c test.c 
# philo_utils.c
BONUS_SRCS = philo_bonus.c philo_bonus_utils.c philo_utils.c
CFLAGS = -Wall -Wextra -pthread -fsanitize=thread -g
# -Werror
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -g -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@make -C clean

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@make -C fclean

re: fclean all

.PHONY: all clean fclean re bonus
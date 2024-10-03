NAME = pipex
BONUS = pipex_bonus
CC = gcc
SRCS = pipex.c pipex_utils.c
BONUS_SRCS = pipex_bonus.c pipex_bonus_utils.c pipex_utils.c
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
MY_LIB = ./libft/libft.a
MY_LIBDIR = ./libft/

all: $(NAME)

$(MY_LIB):
	@make -C $(MY_LIBDIR)

$(NAME): $(MY_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(MY_LIBDIR) -lft -o $(NAME)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(MY_LIB) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@make -C $(MY_LIBDIR) clean

bonus: $(MY_LIB) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(MY_LIBDIR) -lft -o $(BONUS)

fclean: clean
	@make -C $(MY_LIBDIR) fclean
	@rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
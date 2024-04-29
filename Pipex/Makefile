NAME = push_swap
CC = gcc
SRCS = push_swap.c
CFLAGS = -Wall -Wextra -Wextra -g
OBJS = $(SRCS:.c=.o)
MY_LIB = ./libft/libft.a
MY_LIBDIR = ./libft/
.PHONY: all clean fclean re bonus
all: $(NAME)

$(MY_LIB):
	@make -C $(MY_LIBDIR)
$(NAME): $(MY_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MY_LIB) -g -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
fclean:
	@rm -f $(NAME)
	@rm -f $(OBJS)

re: fclean all


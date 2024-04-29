NAME = push_swap
CC = gcc
SRCS = push_swap.c push_swap_utils.c
CFLAGS = -Wall -Wextra -Wextra -g
OBJS = $(SRCS:.c=.o)
MY_LIB = ./libft/libft.a
MY_LIBDIR = ./libft/

all: $(NAME)

$(MY_LIB):
	@make -C $(MY_LIBDIR)

$(NAME): $(MY_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MY_LIB) -g -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C libft clean
	@rm -f $(OBJS)
fclean:
	@make -C libft fclean
	@rm -f $(NAME)
	@rm -f $(OBJS)

re: fclean all




NAME = push_swap
CC = gcc
SRCS = push_swap.c ft_rotation_calculations_ab.c ft_rotation_calculations_ba.c operations_1.c operations_2.c operations_3.c \
		optimize_rotates.c ft_sort.c ft_rotate_type.c ft_rotate.c ft_check_utils.c algorithm.c
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
OBJS = $(SRCS:.c=.o)
MY_LIB = ./libft/libft.a
MY_LIBDIR = ./libft/

all: $(NAME)

$(MY_LIB):
	@make -C $(MY_LIBDIR)

$(NAME): $(MY_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(MY_LIBDIR) -lft -o $(NAME)

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

.PHONY: all clean fclean




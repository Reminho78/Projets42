NAME	= libft.a
CC		= gcc
RM		= rm -f
SRCS	= ft_atoi.c ft_memset.c ft_memcpy.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
		ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c ft_strtrim.c ft_strjoin.c ft_calloc.c ft_strdup.c ft_memmove.c ft_isalpha.c ft_isdigit.c ft_strlen.c ft_bzero.c ft_strlcpy.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_substr.c ft_strlcat.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_printf.c\
		ft_putnbr_base.c get_next_line.c ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstdelone.c ft_lstadd_back.c ft_lstlast.c ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_sort_list.c
CFLAGS	= -Wall -Wextra -Wextra -g
OBJS	= $(SRCS:.c=.o)
LIBC	= ar rcs

all:		$(NAME)


$(NAME):	$(OBJS)
			$(LIBC) $(NAME) $(OBJS)

%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)
fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
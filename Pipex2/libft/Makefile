NAME    = libft.a
CC      = gcc
RM      = rm -f
SRCS    = $(addprefix srcs/, ft_atoi.c ft_memset.c ft_memcpy.c ft_strrchr.c ft_strncmp.c \
			ft_memchr.c ft_memcmp.c ft_strnstr.c ft_printf_utils.c ft_strmapi.c ft_striteri.c \
			ft_itoa.c ft_split.c ft_strtrim.c ft_strjoin.c ft_calloc.c ft_strdup.c ft_memmove.c \
			ft_isalpha.c ft_isdigit.c ft_strlen.c ft_bzero.c ft_strlcpy.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_putstr_fd.c ft_putchar_fd.c ft_substr.c ft_strlcat.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_strchr.c ft_printf.c ft_putnbr_base.c)
CFLAGS  = -Wall -Wextra -Wextra -g
OBJS    = $(addprefix objets/, $(notdir $(SRCS:.c=.o)))
LIBC    = ar rcs

all: objets $(NAME)

objets:
	@mkdir -p objets

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

SRCSBONUS    = $(addprefix srcs/, ft_lstmap_bonus.c ft_lstiter_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
			ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstadd_front_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c)

OBJSBONUS    = $(addprefix objets/, $(notdir $(SRCSBONUS:.c=.o)))

bonus: $(OBJSBONUS)
	$(LIBC) $(NAME) $(OBJSBONUS)

objets/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

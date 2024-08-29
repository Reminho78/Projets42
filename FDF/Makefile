# Nom de l'exécutable
NAME := fdf

# Compilateur et flags
CC := gcc
CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -g
LDFLAGS := -Iinclude -ldl -lglfw -pthread -lm
# LDFLAGS := -framework Cocoa -framework OpenGL -framework IOKit -L/opt/homebrew/lib -lglfw

# Chemins des bibliothèques et headers
LIBMLX := ./MLX42
MY_LIB := ./libft/libft.a
MY_LIBDIR := ./libft/
HEADERS := -I ./include -I $(LIBMLX)/include

# Sources et objets
SRCS := fdf.c
OBJS := $(SRCS:.c=.o)

# Libs pour l'édition de liens
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -pthread -lm -L$(MY_LIBDIR) -lft

# Règles de compilation
all: libmlx $(MY_LIB) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(MY_LIB):
	@make -C $(MY_LIBDIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LDFLAGS) -o $(NAME) && printf "Linking: $(NAME)\n"

clean:
	@rm -rf $(OBJS)
	@make -C $(MY_LIBDIR) clean
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)
	@make -C $(MY_LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re libmlx
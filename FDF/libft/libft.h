/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:54:34 by rcorroy           #+#    #+#             */
/*   Updated: 2024/08/28 11:13:39 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		ft_strncmp(const char *f, const char *s, size_t len);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
long	ft_atoi(const char *str);
int		ft_tolower(int character);
int		ft_toupper(int character);
int		ft_memcmp( const void *p1, const void *p2, size_t n);
int		ft_lstsize(t_stack *lst);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_base(size_t nbr, int is_upper);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_printf(const char *format, ...);

int		manips_percent(int fd);
int		manips_string(va_list args, int fd);
int		manips_char(va_list args, int fd);
int		manips_integer(va_list args, int fd);
int		manips_unsigned(va_list args, int fd);
int		manips_hex_pointer(va_list args, const char *format, int index, int fd);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);

void	ft_bzero(void *s, size_t len);
void	*ft_memchr( const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_putendl_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_lstadd_back(t_stack **stack, t_stack *stack_new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_error(void);
// void	ft_lstclear(t_stack **lst, void (*del)(void *));
// void	ft_lstdelone(t_stack *lst, void (*del)(void *));
// void	ft_lstiter(t_stack *lst, void (*f)(void *));
// t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *));
// t_stack	*sort_stack(t_stack *lst, int (*cmp)(void*, void*));

char	*get_next_line(int fd);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *s, const char *p, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);

t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int content);

#endif
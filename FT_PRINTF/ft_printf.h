/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:04:01 by rcorroy           #+#    #+#             */
/*   Updated: 2024/03/04 17:32:48 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_base(size_t nbr, int is_upper);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);

int		manips_percent(int fd);
int		manips_string(va_list args, int fd);
int		manips_char(va_list args, int fd);
int		manips_integer(va_list args, int fd);
int		manips_unsigned(va_list args, int fd);
int		manips_hex_pointer(va_list args, const char *format, int index, int fd);

#endif
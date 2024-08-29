/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:36:15 by rcorroy           #+#    #+#             */
/*   Updated: 2024/05/01 13:38:59 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	manips_percent(int fd)
{
	return (ft_putchar_fd('%', fd));
}

int	manips_string(va_list args, int fd)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		return (ft_putstr_fd("(null)", fd));
	return (ft_putstr_fd(str, fd));
}

int	manips_char(va_list args, int fd)
{
	int	char_arg;

	char_arg = va_arg(args, int);
	return (ft_putchar_fd((char)char_arg, fd));
}

int	manips_integer(va_list args, int fd)
{
	int	num;

	num = va_arg(args, int);
	return (ft_putnbr_fd(num, fd));
}

int	manips_hex_pointer(va_list args, const char *format, int index, int fd)
{
	int				len;
	unsigned long	num;
	int				is_upper;

	len = 0;
	is_upper = 0;
	if (format[index] == 'p')
	{
		num = (unsigned long)va_arg(args, size_t);
		ft_putstr_fd("0x", fd);
		len += 2;
	}
	else
	{
		if (format[index] == 'X')
		{
			is_upper = 1;
		}
		num = (unsigned int )va_arg(args, unsigned long);
	}
	len += ft_putnbr_base(num, is_upper);
	return (len);
}

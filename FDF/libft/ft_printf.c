/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:20:29 by rcorroy           #+#    #+#             */
/*   Updated: 2024/05/01 13:38:24 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putn_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putn_fd(n / 10, fd);
	count += ft_putchar_fd((n % 10) + '0', fd);
	return (count);
}

int	manips_unsigned(va_list args, int fd)
{
	unsigned int	num_u;

	num_u = va_arg(args, unsigned int);
	return (ft_putn_fd(num_u, fd));
}

int	formatage(va_list args, const char *format, int *i)
{
	int	count;

	count = 0;
	if (format[*i] == '%')
		count += manips_percent(1);
	else if (format[*i] == 's')
		count += manips_string(args, 1);
	else if (format[*i] == 'c')
		count += manips_char(args, 1);
	else if (format[*i] == 'd' || format[*i] == 'i')
		count += manips_integer(args, 1);
	else if (format[*i] == 'u')
		count += manips_unsigned(args, 1);
	else if (format[*i] == 'x' || format[*i] == 'X' || format[*i] == 'p')
		count += manips_hex_pointer(args, format, *i, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += formatage(args, format, &i);
		}
		else
			count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

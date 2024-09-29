/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:20:29 by rcorroy           #+#    #+#             */
/*   Updated: 2024/07/14 20:19:31 by rcorroy      ###   ########.fr       */
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

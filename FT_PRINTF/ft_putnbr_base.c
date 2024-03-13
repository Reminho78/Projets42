/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:10:00 by rcorroy           #+#    #+#             */
/*   Updated: 2024/03/04 17:33:00 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(size_t nbr, int is_upper)
{
	int		len;
	char	*base_lower;
	char	*base_upper;

	len = 0;
	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		len += ft_putnbr_base(nbr / 16, is_upper);
		len += ft_putnbr_base(nbr % 16, is_upper);
	}
	else
	{
		if (is_upper)
			ft_putchar_fd(base_upper[nbr], 1);
		else
			ft_putchar_fd(base_lower[nbr], 1);
		len++;
	}
	return (len);
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

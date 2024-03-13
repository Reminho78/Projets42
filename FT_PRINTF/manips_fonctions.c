/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manips_fonctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:21:25 by rcorroy           #+#    #+#             */
/*   Updated: 2024/03/04 16:40:13 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

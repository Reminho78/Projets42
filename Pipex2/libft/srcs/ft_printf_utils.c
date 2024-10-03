/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:18:44 by rcorroy       #+#    #+#             */
/*   Updated: 2024/07/14 20:20:49 by rcorroy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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

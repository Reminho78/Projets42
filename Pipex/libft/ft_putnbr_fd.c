/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:05:09 by rcorroy           #+#    #+#             */
/*   Updated: 2024/04/10 14:12:39 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		count += ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_putnbr_fd(nbr / 10, fd);
	count += ft_putchar_fd((nbr % 10) + '0', fd);
	return (count);
}
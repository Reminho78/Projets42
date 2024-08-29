/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:10:00 by rcorroy           #+#    #+#             */
/*   Updated: 2024/04/17 12:42:57 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:51:56 by rcorroy           #+#    #+#             */
/*   Updated: 2024/02/25 20:53:06 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// La fonction itoa (Integer TO ASCII) est une fonction non standard de la bibliothèque C qui convertit un entier en une chaîne de caractères (string).

#include "libft.h"

static void	recursive(char *str, long n, int i)
{
	i--;
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	if (n > 9)
		recursive(str, n / 10, i);
	str[i] = (n % 10 + '0');
}

static int	count(long buffer, int len)
{
	while (buffer > 0)
	{
		buffer /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		sign;
	char	*str;
	int		len;

	len = 0;
	nbr = n;
	sign = 1;
	if (nbr < 0)
	{
		len++;
		sign = -1;
	}
	nbr *= sign;
	len = count(nbr, len);
	if (nbr == 0)
		len = 1;
	str = malloc(len + 1);
	if (!(str))
		return (NULL);
	recursive(str, nbr * sign, len);
	str[len] = '\0';
	return (str);
}

/* int main()
{
	int b = -65;
	printf("%s", ft_itoa(b));
} */
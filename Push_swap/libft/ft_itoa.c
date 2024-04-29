/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:51:56 by rcorroy           #+#    #+#             */
/*   Updated: 2024/04/26 15:25:06 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// La fonction itoa (Integer TO ASCII) est une fonction non standard de la bibliothèque C qui convertit un entier en une chaîne de caractères (string).

#include "libft.h"

char *ft_itoa(int nbr) 
{
	if(nbr == -2147483648)
		return("-2147483648\0");
	int n = nbr;
	int len = 0;
	if (nbr <= 0)
	{
		len++;
    	}
	while (n) 
	{
		n /= 10;
		len++;
	}
	char *result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL) 
		return NULL;
	result[len] = '\0';
	if (nbr == 0)
	{
		result[0] = '0';
		return(result);
	}
	if (nbr < 0) 
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr) 
	{
		result[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return result;
}

/* int main()
{
	int b = -+-64445;
	printf("%s", ft_itoa(b));
} */
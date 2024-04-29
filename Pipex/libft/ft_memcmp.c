/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:27:16 by rcorroy           #+#    #+#             */
/*   Updated: 2024/02/26 13:53:34 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Elle est utilisée pour comparer les n premiers octets de deux zones de mémoire.

int
	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

// int main() 
// {
// 	char str[30] = "Salat les amis";
// 	char stp[30] = "Salut les amis";

// 	printf("Avant my_memchr: %s\n", str);// Remplace "World" par "....."
// 	printf("Après my_memchr: %d\n", ft_memcmp(str, stp, 5));
// 	return 0;
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:31:00 by rcorroy           #+#    #+#             */
/*   Updated: 2024/02/26 13:51:13 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Elle est utilisée pour rechercher la première occurrence d'un caractère 
// donné dans une zone de mémoire. La fonction examine les n premiers octets 
// d'une zone de mémoire pointée par s à la recherche du caractère c.

#include "libft.h"

void	*ft_memchr( const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	chr;

	str = (unsigned char *)s;
	chr = (unsigned char )c;
	i = 0;
	while (i < n)
	{
		if (str[i] == chr)
		{
			return ((void *)str + i);
		}
		i++;
	}
	return (NULL);
}

int main() {
	char str[] = "Salut les amis";

	printf("Avant my_memchr: %s\n", str);
	printf("Après my_memchr: %s\n", ft_memchr(str, 101, 17));
}
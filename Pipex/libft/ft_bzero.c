/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:27:45 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/19 12:17:18 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// bzero écrit des octets de valeur zéro ('\0') dans les premiers n 
// octets de la zone mémoire pointée par s.

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*p;
	int				g;
	int				i;

	p = s;
	g = len;
	i = 0;
	while (i < g)
	{
		p[i] = 0;
		i++;
	}
}

// int main() {
// 	char str[50] = "Hello, World!";

// 	printf("Avant my_memset: %s\n", str);
// 	ft_bzero(str + 7, 5); // Remplace "World" par "....."
// 	printf("Après my_memset: %s\n", str);

// 	return 0;
// }
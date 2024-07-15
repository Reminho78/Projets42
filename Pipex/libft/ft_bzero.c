/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:27:45 by rcorroy           #+#    #+#             */
/*   Updated: 2024/07/14 20:15:57 by remidubenar      ###   ########.fr       */
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
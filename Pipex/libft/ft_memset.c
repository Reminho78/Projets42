/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:41:21 by rcorroy           #+#    #+#             */
/*   Updated: 2024/07/14 20:14:29 by rcorroy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* memset remplit les n premiers octets de la zone de mémoire pointée par 
avec l'octet c. C'est une opération bas niveau qui ne tient pas compte du type
des données contenues dans la zone de mémoire ; elle opère purement sur une 
base octet par octet. */

/* Utilisation memset est largement utilisée pour initialiser des zones de 
mémoire à une valeur spécifique avant leur utilisation. Par exemple, elle peut 
être utilisée pour initialiser un tableau d'entiers à zéro, effacer une 
structure à des valeurs par défaut, ou préparer un buffer de données à un 
état connu avant de le remplir avec des données. */

void	*ft_memset(void *b, int c, size_t len)
{
	int				g;
	int				i;
	unsigned char	*p;

	g = len;
	p = b;
	i = 0;
	while (i < g)
	{
		p[i] = c;
		i++;
	}
	return (b);
}

// int main() {
//     char str[50] = "Hello, World!";

//     printf("Avant my_memset: %s\n", str);
//     memset(str + 7, '.', 5); // Remplace "World" par "....."
//     printf("Après my_memset: %s\n", str);

//     return 0;
// }

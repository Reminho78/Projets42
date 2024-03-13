/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:02:07 by rcorroy           #+#    #+#             */
/*   Updated: 2024/02/26 13:37:05 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* strlcpy copie la chaîne src vers dst, incluant le caractère nul terminal, mais 
ne copie pas plus de dstsize - 1 caractères. Cela garantit que dst est toujours 
correctement terminée par un caractère nul, à condition que dstsize soit 
supérieur à zéro.
La fonction retourne la longueur totale de la chaîne qu'elle a tenté de créer, 
c'est-à-dire la longueur de src. Si le retour est supérieur ou égal à dstsize, 
cela indique que la coupure a eu lieu et que le tampon de destination 
n'était pas assez grand pour contenir toute la chaîne source. */

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size > 0)
	{
		while (index < size)
		{
			dest[index] = src[index];
			if (src[index] == '\0')
				return (index);
			index++;
		}
		index--;
		dest[index] = '\0';
	}
	index = 0;
	while (src[index] != '\0')
		index++;
	return (index);
}

int	main(void)
{
	unsigned size = 8;
	char	src[] = "Bonbonuuu";
	char	dest[] = "chichat";
	printf("%s\n", dest);
	ft_strlcpy(dest, src, size);
	printf("%zu\n", ft_strlcpy(dest, src, size));
	printf("%s\n", dest);
	return 0;
}
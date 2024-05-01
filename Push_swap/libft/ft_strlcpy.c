/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:02:07 by rcorroy           #+#    #+#             */
/*   Updated: 2024/05/01 13:30:27 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* strlcpy copie la chaîne src vers dst, incluant le caractère nul terminal,
mais 
ne copie pas plus de dstsize - 1 caractères. Cela garantit que dst est toujours 
correctement terminée par un caractère nul, à condition que dstsize soit 
supérieur à zéro.
La fonction retourne la longueur totale de la chaîne qu'elle a tenté de créer, 
c'est-à-dire la longueur de src. Si le retour est supérieur ou égal à dstsize, 
cela indique que la coupure a eu lieu et que le tampon de destination 
n'était pas assez grand pour contenir toute la chaîne source. */

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[count] != '\0' && count < (size - 1))
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (ft_strlen(src));
}

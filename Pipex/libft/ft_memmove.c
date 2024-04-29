/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:41:39 by rcorroy           #+#    #+#             */
/*   Updated: 2024/02/26 13:57:00 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Elle est utilisée pour copier n octets d'une zone de mémoire source à 
une autre zone de mémoire destination, avec la garantie que la copie se 
déroule de manière correcte même si les zones de mémoire se chevauchent. */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			j;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	j = 1;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		j = -1;
		d += n - 1;
		s += n - 1;
	}
	while (i < n)
	{
		*d = *s;
		d += j;
		s += j;
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	src[] = "Bonbon";
// 	char	dest[] = "Charnaval";

// 	printf("%s\n", dest);
// 	memmove(dest, src, 3);
// 	printf("%s\n", dest);
// }
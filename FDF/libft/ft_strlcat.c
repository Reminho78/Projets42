/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:04:06 by rcorroy           #+#    #+#             */
/*   Updated: 2024/02/26 13:19:28 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* conçue pour éviter les dépassements de buffer
 en prenant une taille maximale du buffer de destination comme argument. */

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	d;
	size_t	di;
	size_t	si;

	si = ft_strlen(src);
	if (!dst && size == 0)
		return (si);
	d = ft_strlen(dst);
	di = d;
	if (size <= di)
		return (size + si);
	s = 0;
	while (src[s] && d + 1 < size)
	{
		dst[d] = src[s];
		s++;
		d++;
	}
	dst[d] = 0;
	return (di + si);
}

// #include <stdio.h>
// int main() {
//      char dest[] = "Hello";
//  char src[] = ", world";
//  unsigned int result = ft_strlcat(dest, src, 2);
//  printf("%s\n", dest);
//  printf("%d\n", result);
//  return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:04:41 by rcorroy           #+#    #+#             */
/*   Updated: 2024/10/03 19:14:23 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* Elle est utilisée pour comparer les n premiers caractères de deux chaînes de
 caractères et déterminer leur ordre lexicographique ou leur égalité. */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}

// int	main()
// {
// 	char s1[]= "couaou";
// 	char s2[]= "coubou";
// 	int p = 3;

// 	printf("%d", ft_strncmp(s1, s2, p));
// }
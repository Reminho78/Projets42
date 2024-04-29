/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:27:34 by rcorroy           #+#    #+#             */
/*   Updated: 2024/02/26 13:47:43 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Elle est utilisée pour localiser la dernière occurrence 
d'un caractère dans une chaîne. */

char
	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

/* int main()
{
	int p = 101;
	char phrase[] = "Bonjour les emis";
	printf("%s", phrase);
	printf("\n%s", ft_strrchr(phrase, p));
} */
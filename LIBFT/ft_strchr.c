/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:10:53 by rcorroy           #+#    #+#             */
/*   Updated: 2024/03/12 20:27:41 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Elle est utilisée pour localiser la première occurrence
 d'un caractère dans une chaîne. Cette fonction
recherche un caractère spécifié c dans la chaîne pointée par s. */

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

int main()
{
	int p = 10;
	char phrase[] = "Bonjour les amis\ncaca boudin";
	printf("%s", phrase);
	printf("\n%s", ft_strchr(phrase, p));
}
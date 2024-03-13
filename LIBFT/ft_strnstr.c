/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:20:13 by rcorroy           #+#    #+#             */
/*   Updated: 2024/03/02 17:34:37 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* strnstr est utilisée pour rechercher une sous-chaîne (needle) dans une chaîne
 (haystack) mais en limitant la recherche à un certain nombre de caractères. */

/*  Retourne un pointeur vers le premier caractère de la première occurrence de needle 
 dans haystack si needle est trouvé dans les len premiers caractères de haystack.
Retourne NULL si needle n'est pas trouvé ou si needle est une chaîne vide. */

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str && !len)
		return (0);
	if (to_find[0] == '\0' || to_find == str)
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j) < len)
		{
			if (str[i + j] == '\0' && to_find[j] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		if (to_find[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (0);
}

int main()
{
char pt[]="hello como esta ?";
char pq[]="l";
printf("%s", ft_strnstr(pt, pq, 4));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:31:49 by rcorroy           #+#    #+#             */
/*   Updated: 2024/07/14 20:13:11 by rcorroy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Alloue (avec malloc(3)) et retourne une chaîne de
caractères issue de la chaîne ’s’.
Cette nouvelle chaîne commence à l’index ’start’ et
a pour taille maximale ’len’. */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*tab;

	size = 0;
	if (s)
		size = ft_strlen(s);
	if (start > size)
		return (ft_strdup(""));
	if (start + len > size && start < size)
		len = size - start;
	tab = malloc(len + 1);
	if (!tab || !s)
		return (NULL);
	i = (size_t)start;
	j = 0;
	while (s[i] != '\0' && j < len)
	{
		tab[j] = s[i];
		i++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

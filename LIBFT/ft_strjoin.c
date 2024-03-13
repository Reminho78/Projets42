/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:50:20 by rcorroy           #+#    #+#             */
/*   Updated: 2024/02/26 13:15:08 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* La fonction strjoin est typiquement utilisée pour créer une nouvelle chaîne de 
caractères en joignant deux chaînes ou plus, souvent avec un caractère ou une 
chaîne de séparation spécifique entre chaque élément. */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	tab = malloc(len + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		tab[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2[len] != '\0')
	{
		tab[i] = s2[len];
		i++;
		len++;
	}
	tab[i] = '\0';
	return (tab);
}

// int	main()
// {
// 	char	chaine1[] = "CocaCola ";
// 	char	chaine2[] = ", c'est trop bon";
// 	printf("%s", chaine1);
// 	printf("\n%s", chaine2);
// 	printf("\n%s", ft_strjoin(chaine1, chaine2));
// }
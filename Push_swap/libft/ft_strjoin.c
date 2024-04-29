/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:50:20 by rcorroy           #+#    #+#             */
/*   Updated: 2024/04/18 13:19:52 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* La fonction strjoin est typiquement utilisée pour créer une nouvelle chaîne de 
caractères en joignant deux chaînes ou plus, souvent avec un caractère ou une 
chaîne de séparation spécifique entre chaque élément. */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result == NULL)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

// int	main()
// {
// 	char	chaine1[] = "CocaCola ";
// 	char	chaine2[] = ", c'est trop bon";
// 	printf("%s", chaine1);
// 	printf("\n%s", chaine2);
// 	printf("\n%s", ft_strjoin(chaine1, chaine2));
// }
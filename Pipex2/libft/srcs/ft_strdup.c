/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:25:56 by rcorroy           #+#    #+#             */
/*   Updated: 2024/10/03 19:14:23 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* Elle est conçue pour dupliquer une chaîne de caractères, en allouant 
de la mémoire pour la nouvelle chaîne et en copiant le contenu de la 
chaîne originale vers cette nouvelle zone mémoire. */

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(src);
	dest = (char *)malloc(size * sizeof(char) + 1);
	if (dest == NULL)
		return (0);
	ft_memcpy(dest, src, size);
	dest[size] = '\0';
	return (dest);
}

// int main() {
//     const char *original = "Hello, world!";
//     char *copy = ft_strdup(original);

//     if (copy != NULL) {
//         printf("Original: %s\nCopy: %s\n", original, copy);
//         free(copy); // N'oubliez pas de libérer la mémoire allouée
//     } else {
//         printf("Failed to allocate memory for copy.\n");
//     }

//     return 0;
// }
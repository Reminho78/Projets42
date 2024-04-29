/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:32:09 by rcorroy           #+#    #+#             */
/*   Updated: 2024/02/25 20:51:17 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Contrairement à malloc, qui alloue simplement un bloc de mémoire sans initialiser son contenu, calloc alloue de la mémoire et initialise tous les bits à zéro.

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	array = (void *)malloc(count * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, (count * size));
	return (array);
}

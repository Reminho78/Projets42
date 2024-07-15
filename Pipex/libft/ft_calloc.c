/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:32:09 by rcorroy           #+#    #+#             */
/*   Updated: 2024/07/14 20:12:38 by remidubenar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Contrairement à malloc, qui alloue simplement un bloc de mémoire sans 
// initialiser son contenu, calloc alloue de la mémoire et initialise tous les
// bits à zéro.

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

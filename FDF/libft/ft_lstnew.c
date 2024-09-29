/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:55:27 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/29 14:00:25 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Alloue (avec malloc(3)) et renvoie un nouvel
élément. La variable membre ’content’ est
initialisée à l’aide de la valeur du paramètre
’content’. La variable ’next’ est initialisée à
NULL. */

t_stack	*ft_lstnew(int content)
{
	t_stack	*newlst;

	newlst = malloc(sizeof(t_stack));
	if (!newlst)
	{
		return (NULL);
	}
	newlst->nbr = content;
	newlst->next = NULL;
	return (newlst);
}

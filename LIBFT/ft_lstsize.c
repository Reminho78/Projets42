/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:24:24 by rcorroy            #+#    #+#             */
/*   Updated: 2024/02/26 13:11:10 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compte le nombre d’éléments de la liste.

int	ft_lstsize(t_list *lst)
{
	size_t	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		size++;
		lst = lst->next;
	}
	size++;
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsadd_back_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:48:18 by onault            #+#    #+#             */
/*   Updated: 2024/02/26 13:12:35 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Ajoute l’élément ’new’ à la fin de la liste.

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*live;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	live = *lst;
	while (live->next != NULL)
		live = live->next;
	live->next = new;
}

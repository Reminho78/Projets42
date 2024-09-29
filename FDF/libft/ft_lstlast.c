/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:43:58 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/29 14:00:18 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Renvoie le dernier élément de la liste.
t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

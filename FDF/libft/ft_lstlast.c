/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:43:58 by onault            #+#    #+#             */
/*   Updated: 2024/08/27 17:31:11 by remidubenar      ###   ########.fr       */
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

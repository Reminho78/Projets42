/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:48:12 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/29 13:59:53 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Itère sur la liste ’lst’ et applique la fonction
’f ’au contenu de chaque élément. Crée une nouvelle
liste résultant des applications successives de
’f’. La fonction ’del’ est là pour détruire le
contenu d’un élément si nécessaire. */
// t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_stack	*newlst;
// 	t_stack	*new;

// 	newlst = NULL;
// 	while (lst)
// 	{
// 		new = ft_lstnew(f(lst->nbr));
// 		if (!new)
// 		{
// 			ft_lstclear(&newlst, del);
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&newlst, new);
// 		lst = lst->next;
// 	}
// 	return (newlst);
// }

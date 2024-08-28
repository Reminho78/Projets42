/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:25:26 by onault            #+#    #+#             */
/*   Updated: 2024/08/27 18:24:49 by remidubenar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Supprime et libère la mémoire de l’élément passé en
paramètre, et de tous les éléments qui suivent, à
l’aide de ’del’ et de free(3)
Enfin, le pointeur initial doit être mis à NULL. */

// void	ft_lstclear(t_stack **lst, void (*del)(void *))
// {
// 	t_stack	*ls;

// 	ls = *lst;
// 	if (!*lst)
// 		return ;
// 	while (ls != NULL)
// 	{
// 		*lst = ls->next;
// 		del(ls->nbr);
// 		free(ls);
// 		ls = *lst;
// 	}
// 	*lst = NULL;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 01:19:20 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/30 01:19:22 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Libère la mémoire de l’élément passé en argument en
utilisant la fonction ’del’ puis avec free(3). La
mémoire de ’next’ ne doit pas être free. */

// void	ft_lstdelone(t_stack *lst, void (*del)(void *))
// {
// 	if (!lst)
// 		return ;
// 	del(lst->nbr);
// 	free(lst);
// 	lst = NULL;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:00:36 by onault            #+#    #+#             */
/*   Updated: 2024/08/27 18:25:03 by remidubenar      ###   ########.fr       */
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

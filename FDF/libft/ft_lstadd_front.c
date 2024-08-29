/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:10:40 by onault            #+#    #+#             */
/*   Updated: 2024/08/27 17:17:29 by remidubenar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Ajoute l’élément ’new’ au début de la liste.

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

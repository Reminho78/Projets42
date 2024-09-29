/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:10:40 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/29 13:59:15 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Ajoute l’élément ’new’ au début de la liste.

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:58:10 by rcorroy           #+#    #+#             */
/*   Updated: 2024/05/01 13:59:57 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(f_list *newNode, f_list *List)
{
	f_list	*current;

	current = List;
	while (1)
	{
		if (newNode->value == current->value)
			return (1);
		current = current->next;
		if (current == List)
			break ;
	}
	return (0);
}

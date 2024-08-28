/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remidubenard <remidubenard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:59:05 by remidubenar       #+#    #+#             */
/*   Updated: 2024/08/28 10:59:13 by remidubenar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// t_stack	*sort_stack(t_stack *lst, int (*cmp)(void*, void*))
// {
// 	void	*swap;
// 	t_stack	*tmp;

// 	tmp = lst;
// 	while (lst->next != NULL)
// 	{
// 		if (((*cmp)(lst->nbr, lst->next->nbr)) == 0)
// 		{
// 			swap = lst->nbr;
// 			lst->nbr = lst->next->nbr;
// 			lst->next->nbr = swap;
// 			lst = tmp;
// 		}
// 		else
// 			lst = lst->next;
// 	}
// 	lst = tmp;
// 	return (lst);
// }

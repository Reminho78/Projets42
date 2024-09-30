/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:07:46 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/30 22:41:47 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_maj_index(t_stack *a)
{
	int		i;

	i = 0;
	while (a)
	{
		i++;
		a->index = i;
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;

	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}

	// t_stack		*initial_a;
	// int			i;

	// i = 0;

	// initial_a = a;
	// while (initial_a)
	// {
	// 	printf("number:%ld index: %ld\n", initial_a->nbr, initial_a->index);
	// 	initial_a = initial_a->next;
	// 	i++;
	// }
	// ft_maj_index(initial_a);
	// printf("nombre de nombres : %d\n", i);
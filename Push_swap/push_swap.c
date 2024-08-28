/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:07:46 by rcorroy           #+#    #+#             */
/*   Updated: 2024/08/28 11:25:16 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksorted(a))
		ft_sort(&a);
	int i = 0;
	t_stack *initial_a = a;
	while(initial_a)
	{
		printf("number:%ld index: %ld\n", initial_a->nbr, initial_a->index);
		initial_a = initial_a->next;
		i++;
	}
	printf("nombre de nombres : %d\n", i);
	ft_free(&a);
	return (0);
}

	// int i = 0;
	// t_stack *initial_a = a;
	// while(initial_a)
	// {
	// 	printf("number:%ld index: %ld\n", initial_a->nbr, initial_a->index);
	// 	initial_a = initial_a->next;
	// 	i++;
	// }
	// printf("nombre de nombres : %d\n", i);

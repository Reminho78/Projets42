/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:04:48 by rcorroy           #+#    #+#             */
/*   Updated: 2024/05/01 14:44:57 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char**av)
{
	t_list2	*lista;
	t_list2	*listb;

	lista = NULL;
	listb = NULL;
	ft_printf("%d\n", ac);
	if (ac == 2)
	{
		if (arg_is_one(av[1], &lista) == 1)
			return (0);
	}
	else
		arg_is_more_then_one(ac, av, &lista);
	// SwapFirstTwo(&lista); 
	print_lists(lista, listb);
	shift_down(&lista, &listb, LISTE_A);
	print_lists(lista, listb);
	swap_first_two(&lista, &listb, LISTE_A);
	print_lists(lista, listb);
	move_node(&lista, &listb, LISTE_A);
	move_node(&lista, &listb, LISTE_A);
	print_lists(lista, listb);
}

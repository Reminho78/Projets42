/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:07:38 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/30 01:24:17 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Ces fonctions calculent combien de fois nous devons
// faire pivoter les piles ensemble.

// Parce qu'après un certain nombre de rotations, nous allons
// procéder uniquement avec la rotation d'une seule pile.
//i correspond au nombre de rotations
int	ft_rotate_simultane_ra_rb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ft_find_place_b(b, c);
	if (i < ft_find_index(a, c))
		i = ft_find_index(a, c);
	return (i);
}

// Parce qu'après un certain nombre de rotations, nous allons
// procéder uniquement avec une seule rotation de pile.
// Ici, au lieu de vérifier avec le numéro d'index normal,
// nous utilisons la rotation inverse,
// c'est-à-dire l'index inverse, qui est calculé en faisant la taille
// de la liste moins le numéro d'index.
int	ft_case_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = ft_lstsize(b) - ft_find_place_b(b, c);
	if ((i < (ft_lstsize(a) - ft_find_index(a, c))) && ft_find_index(a, c))
		i = ft_lstsize(a) - ft_find_index(a, c);
	return (i);
}

// Cette fonction effectue les mêmes calculs pour le cas rra + rb.
int	ft_case_rrarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(a, c))
		i = ft_lstsize(a) - ft_find_index(a, c);
	i = ft_find_place_b(b, c) + i;
	return (i);
}

// Cette fonction effectue les mêmes calculs pour le cas ra + rrb.
int	ft_case_rarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = ft_lstsize(b) - ft_find_place_b(b, c);
	i = ft_find_index(a, c) + i;
	return (i);
}

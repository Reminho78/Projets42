/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:07:46 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/30 01:32:00 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function sorts the stack_a if there are more 
// than 2 elements in the stack_a.
// And finally it makes final sort in stack_a after
// all values pushed to stack_b, sorted and pushed
// back to stack_a. Because, even the stack_a is
// sorted at the end, the minimum number have to 
// at the top of the stack_a. So, it simply brings
// the smallest number of the stack_a to the top.
void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
	{
		ft_sa(stack_a, 0);
	}
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		i = ft_find_index(*stack_a, ft_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->nbr != ft_min(*stack_a))
				ft_ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->nbr != ft_min(*stack_a))
				ft_rra(stack_a, 0);
		}
	}
	ft_maj_index(*stack_a);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*initial_a;
	int			i;

	a = ft_process(argc, argv);
	i = 0;
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksorted(a))
		ft_sort(&a);
	initial_a = a;
	while (initial_a)
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

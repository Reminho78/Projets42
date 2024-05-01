/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:59:10 by rcorroy           #+#    #+#             */
/*   Updated: 2024/05/01 14:42:08 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

typedef struct t_list2
{
	int				value;
	int				index;
	struct t_list2	*prev;
	struct t_list2	*next;
}	t_list2;

typedef enum Liste
{
	LISTE_A,
	LISTE_B,
	LISTE_A_et_LISTE_B
}	t_list_type;

t_list2	*create_node(int a, int index);

void	push_front_list(t_list2 **source, t_list2 **dest);
void	print_lists(t_list2 *a, t_list2 *b);
void	swap_firs_two(t_list2 **head, t_list2 **head2, t_list_type type);
void	maj_index_list(t_list2 **head_ref);
void	move_node(t_list2 **headA_ref, t_list2 **headB_ref, t_list_type type);
void	shift_down(t_list2 **head_ref, t_list2 **head_ref2, t_list_type type);
void	shift_up(t_list2 **head_ref, t_list2 **head_ref2, t_list_type type);
void	arg_is_more_then_one(int ac, char **av, t_list2 **ListA);

int		push_back(t_list2 **head, char *a, int index);
int		arg_is_one(char *v, t_list2 **List);
int		check_double(t_list2 *newNode, t_list2 **List);
int		check_int_limits(char*a);
#endif
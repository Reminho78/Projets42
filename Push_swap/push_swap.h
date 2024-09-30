/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:09:01 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/30 21:56:17 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"

void		alpha_check(char **argv);
void		ft_maj_index(t_stack *a);
void		ft_free(t_stack **lst);
void		ft_ra(t_stack **a, int j);
void		ft_rb(t_stack **b, int j);
void		ft_sa(t_stack **a, int j);
void		ft_pa(t_stack **a, t_stack **b, int j);
void		ft_pb(t_stack **stack_a, t_stack **stack_b, int j);
void		ft_rra(t_stack **a, int j);
void		ft_ss(t_stack **a, t_stack **b, int j);
void		ft_rr(t_stack **a, t_stack **b, int j);
void		ft_rrr_sub(t_stack **b, int j);
void		ft_rrr(t_stack **a, t_stack **b, int j);
void		ft_sort(t_stack **stack_a);
void		ft_sort_three(t_stack **stack_a);
void		ft_rrb(t_stack **b, int j);
void		ft_sb(t_stack **b, int j);
void		ft_sort_and_mouv_until_3(t_stack **stack_a, t_stack **stack_b);

int			ft_checksorted(t_stack *stack_a);
int			check_args(char **argv);
int			check_error(char **argv, int i, int j);
int			ft_checkdup(t_stack *a);
int			ft_min(t_stack *a);
int			ft_max(t_stack *a);
int			ft_find_index(t_stack *a, int nbr);
int			ft_find_place_b(t_stack *stack_b, int nbr_push);
int			ft_find_place_a(t_stack *a, int nbr);
int			ft_case_rarb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rrarrb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rarrb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rrarb_a(t_stack *a, t_stack *b, int c);
int			ft_rotate_simultane_ra_rb(t_stack *a, t_stack *b, int c);
int			ft_case_rrarrb(t_stack *a, t_stack *b, int c);
int			ft_case_rrarb(t_stack *a, t_stack *b, int c);
int			ft_case_rarrb(t_stack *a, t_stack *b, int c);
int			ft_rotate_type_ab(t_stack *a, t_stack *b);
int			ft_rotate_type_ba(t_stack *a, t_stack *b);
int			ft_ra_rb(t_stack **a, t_stack **b, int c, char s);
int			ft_rra_rrb(t_stack **a, t_stack **b, int c, char s);
int			ft_rra_rb(t_stack **a, t_stack **b, int c, char s);
int			ft_ra_rrb(t_stack **a, t_stack **b, int c, char s);

t_stack		*ft_process(int argc, char **argv);
t_stack		*ft_sub_process(char **argv);
t_stack		**ft_sort_a(t_stack **stack_a, t_stack **stack_b);
t_stack		*ft_sort_b(t_stack **stack_a);

#endif
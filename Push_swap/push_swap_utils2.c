/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:39:54 by rcorroy           #+#    #+#             */
/*   Updated: 2024/05/01 14:51:41 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_node(t_list2 **headA_ref, t_list2 **headB_ref, t_list_type type)
{
	if (*headA_ref == NULL)
		return;

	if (type == LISTE_A)
		printf("pa\n");
	if (type== LISTE_B)
		printf("pb\n");

	t_list2 *first_node_a = *headA_ref;
	t_list2 *last_node_a = (*headA_ref)->prev;
	
	if(((*headA_ref)->next != *headA_ref) && ((*headA_ref)->prev != *headA_ref))
	{
		*headA_ref = (*headA_ref)->next;
		(*headA_ref)->prev = last_node_a;
		(*headA_ref)->prev->next = *headA_ref;
	}
	else
	{
		*headA_ref = NULL;
	}
	
	if (*headB_ref == NULL)
		{
			// Si la liste B est vide
			*headB_ref = first_node_a;
			(*headB_ref)->prev = first_node_a;
			(*headB_ref)->next = first_node_a;
	}
	else
	{
			// Si la liste B n'est pas vide
			t_list2 *frst_node_b = *headB_ref;
			t_list2 *last_node_b = (*headB_ref)->prev;
			*headB_ref = first_node_a;
			(*headB_ref)->prev = last_node_b;
			(*headB_ref)->next = frst_node_b;
			frst_node_b->prev = first_node_a;
			(*headB_ref)->prev->next = first_node_a;
	}
	maj_index_list(headA_ref);
	maj_index_list(headB_ref);
}

void swap_first_two(t_list2** head, t_list2** head2,t_list_type type)
{
	int temp;

	if (*head == NULL || (*head)->next == *head)
	{
		printf("La liste contient moins de deux éléments, impossible d'échanger.\n");
		return;
	}
	if (type == LISTE_A)
		printf("sa\n");
	else if (type== LISTE_B)
		printf("sb\n");
	if(type == LISTE_A_et_LISTE_B && !(*head2 == NULL || (*head2)->next == *head2))
	{
		printf("ss\n");
		t_list2* first = *head2;
		t_list2* second = (*head2)->next;
		temp = first->value;
		first->value = second->value;
		second->value = temp;
	}
	(void) head2;
	t_list2* first = *head;
	t_list2* second = (*head)->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

// premier devient dernier
void shift_up(t_list2 **head_ref, t_list2 **head_ref2, t_list_type type)
{
	if (*head_ref == NULL || (*head_ref)->next == *head_ref)
		return;

	if (type == LISTE_A)
		printf("ra\n");
	if (type== LISTE_B)
		printf("rb\n");

	if((type == LISTE_A_et_LISTE_B) && !(*head_ref2 == NULL || (*head_ref2)->next == *head_ref2))
	{
		printf("rr\n");
		*head_ref2 = (*head_ref2)->next;
		maj_index_list(head_ref2);
	}
	(void) head_ref2;
	*head_ref = (*head_ref)->next;
	maj_index_list(head_ref);
}

// dernier devient premier
void shift_down(t_list2 **head_ref, t_list2 **head_ref2, t_list_type type)
{
	if (*head_ref == NULL || (*head_ref)->prev == *head_ref)
		return;
	
	if (type == LISTE_A)
		printf("rra\n");
	if (type== LISTE_B)
		printf("rrbb\n");

	if((type == LISTE_A_et_LISTE_B) && !(*head_ref2 == NULL || (*head_ref2)->next == *head_ref2))
	{
		printf("rrr\n");
		*head_ref2 = (*head_ref2)->prev;
		maj_index_list(head_ref2);
	}
	(void) head_ref2;
	*head_ref = (*head_ref)->prev;
	maj_index_list(head_ref);
}

void print_lists(t_list2 *a, t_list2 *b)
{
	ft_printf("\n");
	if ((a == NULL && b == NULL))
	{
		ft_printf("Les listes a et b sont vides.\n");
		return;
	}
	else if (a == NULL && b != NULL)
	{
		ft_printf("liste A    liste B\n");
		t_list2 *karen = b;
		while(1)
		{
			ft_printf("Vide       value : %d index : %d\n",karen->value, karen->index);
			karen = karen->next;
			if (karen == b)
				break;
		}
	}
	else if(a != NULL && b == NULL)
	{
		ft_printf("liste A                  liste B\n");
		t_list2 *current = a;
		while(1)
		{
			ft_printf("value : %d index : %d      Vide\n", current->value, current->index);
			current = current->next;
			if (current == a)
				break;
		}
	}
	else if(a != NULL && b != NULL)
	{
		ft_printf("liste A                  liste B\n");
		t_list2 *karen = b;
		t_list2 *current = a;
		while(1)
		{
			ft_printf("value : %d index : %d      value : %d index : %d\n", current->value, current->index, karen->value, karen->index);
			current = current->next;
			karen = karen->next;
			if(current == a || karen == b)
			{
				break;
			}
		}
		if(current != a)
		{
			while(1)
			{
				ft_printf("value : %d index : %d      Vide\n", current->value, current->index);
				current = current->next;
				if (current == a)
				{
					break;
				}
			}
		}
		if(karen != b)
		{
			while(1)
			{
				ft_printf("Vide                      value : %d index : %d\n",karen->value, karen->index);
				karen = karen->next;
				if (karen == b)
				{
					break;
				}
			}
		}
	}
}
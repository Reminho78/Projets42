/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:14:16 by rcorroy           #+#    #+#             */
/*   Updated: 2024/04/26 17:56:50 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

f_list *createNode(int a , int index)
{
	f_list *newNode = malloc(sizeof(f_list));
	
	if(newNode == NULL)
	{
		ft_printf("Erreur avec malloc");
		return NULL;
	}
	newNode->value = a;
	newNode->index = index;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void pushFront(f_list **head, char *a , int index)
{
	f_list *newNode = createNode(ft_atoi(a), index);
	if (*head == NULL)
	{
		*head = newNode;
		(*head)->next = newNode;
		(*head)->prev = newNode;
	}
	else 
	{
		newNode->prev = (*head)->prev;
		newNode->next = *head;
		(*head)->prev->next = newNode;
		(*head)->prev = newNode;
		*head = newNode;
	}
}

void pushBack(f_list **head, char *a , int index)
{
	f_list *newNode = createNode(ft_atoi(a), index);
	if(*head == NULL)
	{
		*head = newNode;
		(*head)->next = newNode;
		(*head)->prev = newNode;
	}
	else
	{
		newNode->prev = (*head)->prev;
		newNode->next = *head;
		(*head)->prev->next = newNode;
		(*head)->prev = newNode;
	}
}

void printLists(f_list *a, f_list *b)
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
		f_list *karen = b;
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
		f_list *current = a;
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
		f_list *karen = b;
		f_list *current = a;
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
				if (current == b)
					break;
			}
		}
		if(karen != b)
		{
			while(1)
			{
				ft_printf("Vide       value : %d index : %d\n",karen->value, karen->index);
				karen = karen->next;
				if (karen == a)
					break;
			}
		}
		
	}
}
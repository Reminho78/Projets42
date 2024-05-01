/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:14:16 by rcorroy           #+#    #+#             */
/*   Updated: 2024/05/01 14:50:41 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list2	*create_node(int a, int index)
{
	t_list2	*new_node;

	new_node = malloc(sizeof(t_list2));
	if (new_node == NULL)
	{
		ft_printf("Erreur avec malloc");
		return (NULL);
	}
	new_node->value = a;
	new_node->index = index;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void push_front_list(t_list2 **source, t_list2 **dest)
{
	if (*source == NULL)
	{
		printf("La liste source est vide.\n");
		return;
	}
	if(*dest == NULL)
	{
		(*source)->prev->next = (*source)->next;
		*source = (*source)->next;
	}
	else
	{
		(*source)->prev = (*dest)->prev;
		(*source)->next = (*dest);
		(*dest)->prev->next = *source;
		(*dest)->prev = *source;
	}
}

int arg_is_one(char *v, t_list2 **List)
{
	int	i;
	int	b;
	int	p;
	int	count_str;
	
	count_str = 0;
	i = 0;
	while(v[i] != '\0')
	{
		while(v[i] <= 32)
		{
			i++;
		}
		if(!(v[i] == '-' || v[i] == '+' || (v[i] >= '0' && v[i] <= '9') || (v[i] <= 32)))
		{
			ft_printf("Error");
			exit(0);
		}
		b = 0;
		p = i;
		while(v[i] == '-' || v[i] == '+' || (v[i] >= '0' && v[i] <= '9'))
		{
			b++;
			i++;
		}
		if(b > 0)
		{
			char *u = malloc(sizeof(char) * b);
			b = 0;
			while(v[p] == '-' || v[p] == '+' || (v[p] >= '0' && v[p] <= '9'))
			{
				u[b++] = v[p++];
			}
			if(u)
			{
				count_str++;
				if(pushBack(List, u, count_str) != 0)
					exit(0);
			}
		}
	}
	return count_str;
}

int push_back(t_list2 **head, char *a , int index)
{
	if(check_int_limits(a) == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	t_list2 *new_node = createNode(ft_atoi(a), index);
	if(*head == NULL)
	{
		*head = new_node;
		(*head)->next = new_node;
		(*head)->prev = new_node;
	}
	else
	{
		if(check_double(new_node, head) == 1)
		{
			ft_printf("Error");
			return (2);
		}
		new_node->prev = (*head)->prev;
		new_node->next = *head;
		(*head)->prev->next = new_node;
		(*head)->prev = new_node;
	}
	return (0);
}

void arg_is_more_then_one(int ac, char **av, t_list2 **ListA)
{
	int i;
		
	i = 1;
	while(i < ac)
	{	
		if(pushBack(ListA, av[i], i) != 0)
			exit(0);
		i++;
	}
}

int	check_double(t_list2 *new_node, t_list2 **List)
{
	t_list2 *current = *List;
	while(1)
	{
		if(new_node->value == current->value)
			return 1;
		current = current->next;
		if (current == *List)
			break;
	}
	return 0;
}

int	check_int_limits(char*a)
{
	int i;
	i = 0;
	if(a[0] == '-')
	{
		if(ft_strlen(a) > 11)
			return 1;
		i++;
		while(a[i] && ft_strlen(a) == 11)
		{
			if(a[1] > '2' || a[2] > '1' || a[3] > '4'|| a[4] > '7'|| a[5] > '4'|| a[6] > '8'|| a[7] > '3'|| a[8] > '6'|| a[9] > '4'|| a[10] > '8')
				return 1;
			i++;
		}
		return 0;
	}
	else if(a[0] != '-' && ft_strlen(a) > 10)
			return 1;
	else
	{
		while(a[i] && ft_strlen(a) == 10)
		{
			if(a[0] > '2' || a[1] > '1' || a[2] > '4'|| a[3] > '7'|| a[4] > '4'|| a[5] > '8'|| a[6] > '3'|| a[7] > '6'|| a[8] > '4'|| a[9] > '7')
				return 1;
			i++;
		}
	}
	return 0;
}

void maj_index_list(t_list2 **head_ref)
{
	t_list2 *current = *head_ref;
	int new_index = 1;
	if (*head_ref != NULL)
	{
		while (1)
		{
			current->index = new_index++;
			current = current->next;
			if (current == *head_ref)
				break;
		}
	}
}

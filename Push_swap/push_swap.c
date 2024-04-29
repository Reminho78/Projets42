/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:04:48 by rcorroy           #+#    #+#             */
/*   Updated: 2024/04/26 21:32:49 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swapFirstTwoOfA(f_list** head)
{
	if (*head == NULL || (*head)->next == *head) {
		printf("La liste contient moins de deux éléments, impossible d'échanger.\n");
		return;
	}

	f_list* first = *head;
	f_list* second = (*head)->next;

	int temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void moveNode(f_list** source, f_list** dest, f_list* nodeToMove)
{
	// Vérifier si la source ou le nœud à déplacer est NULL
	if (*source == NULL || nodeToMove == NULL) {
		printf("Erreur: La source ou le nœud à déplacer est NULL.\n");
		return;
	}

	// Si la source contient un seul nœud
	if (*source == nodeToMove && (*source)->next == *source) {
		*source = NULL;
	}
	// Si le nœud à déplacer est la tête de la source
	else if (*source == nodeToMove)
	{
		*source = (*source)->next;
	}

	// Si la destination est vide
	if (*dest == NULL) {
		*dest = nodeToMove;
		nodeToMove->next = nodeToMove;
		nodeToMove->prev = nodeToMove;
	} 
	else
	{
		// Insérer le nœud à déplacer à la fin de la destination
		nodeToMove->next = *dest;
		nodeToMove->prev = (*dest)->prev;
		(*dest)->prev->next = nodeToMove;
		(*dest)->prev = nodeToMove;
	}
    // Mise à jour de l'index dans la liste source
		f_list* currentDest = *dest;
		// if (*dest != NULL)
		// {
		// 	int newIndex = 1;
		// 	while (currentDest != currentDest->prev)
		// 	{
		// 		currentDest->index = newIndex++;
		// 		currentDest = currentDest->next;
		// 	}
		// 	currentDest->prev->index = newIndex++;
		// }
    if (*source != NULL)
	{
        currentDest = *source;
		int newIndex = 1;
		while (currentDest != (*source)->prev)
		{
			currentDest->index = newIndex++;
			currentDest = currentDest->next;
		}
    }
}
/* int checkList(t_list **head)
{
	t_list *current = *head;
	
} */
void arg_is_one(char *v, f_list **List)
{
	int i;
		int b;
		int p;
		int count_arg;
		
		count_arg = 1;
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
					pushBack(List, u, count_arg++);
				}
			}
		}
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

int	check_double(int ac, char **a, f_list **List)
{
	int i;

	i = 3;
	while(i < ac)
	{
		while(1)
		{
			f_list *current = *List;
			if(ft_atoi(a[i]) == current->value)
				return 1;
			current = current->next;
			if (current == *List)
				break;
		}
		i++;
	}
	return 0;
}

int main(int ac, char**av)
{
	ft_printf("%d\n", ac);
	printf("%ld\n", ft_atoi(av[1]));

	f_list *ListA = NULL;
	f_list *ListB = NULL;
	
	if(ac == 2)
	{
		if(check_int_limits(av[1]) == 1)
		{
			ft_printf("Error");
			return 0;
		}
		arg_is_one(av[1], &ListA);
	}
	else
	{
		int i;
		
		i = 1;
		while((ac > 2) && (i < ac))
		{	
			if((check_int_limits(av[i]) == 1) || ((ListA) && (i >= 3) && (check_double(ac, av, &ListA) == 1)))
			{
				ft_printf("Error");
				return 0;
			}
			pushBack(&ListA, av[i], i);
			i++;
		}
	}
	printLists(ListA, ListB); 
	/* swapFirstTwoOfA(&ListA); */
	// moveNode(&ListA, &ListB, ListA);
	// moveNode(&ListA, &ListB, ListA);
	// moveNode(&ListA, &ListB, ListA);
	// printLists(ListA, ListB); 
}
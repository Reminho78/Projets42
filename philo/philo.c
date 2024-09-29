/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 03:07:37 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/03 16:58:31 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

long	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

// Fonction simulant le comportement du philosophe
void* philosopher_routine(void* arg)
{
	t_philosopher *philo = (t_philosopher*)arg;
	// Ajouter ici la logique pour manger, dormir, etc.
	return NULL;
}

// Fonction pour ajouter un philosophe à la liste chaînée circulaire
t_philosopher	*add_philosopher(t_philosopher **head, int index) {
	t_philosopher *new_philo = malloc(sizeof(t_philosopher));
	if (!new_philo)
		return NULL;

	new_philo->index = index;
	new_philo->next = NULL;

	if (*head == NULL) {
		*head = new_philo;
		new_philo->next = new_philo;  // Le premier élément pointe vers lui-même pour former la boucle
	} else {
		t_philosopher *temp = *head;
		while (temp->next != *head) {
			temp = temp->next;
		}
		temp->next = new_philo;
		new_philo->next = *head; // Le nouveau philosophe pointe vers le premier pour fermer la boucle
	}
	return new_philo;
}

int is_pair(int num)
{
    return num % 2;
}


/* int main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		int num_philosophers = ft_atoi(av[1]);
		t_philosopher *philosophers = NULL;
		t_philosopher *current = NULL;
		int i = 1;

		// Initialiser et créer les threads pour chaque philosophe
		while (i <= num_philosophers)
		{
			current = add_philosopher(&philosophers, i);
			if (!current)
			{
				printf("Failed to create philosopher %d\n", i);
				return 1;
			}
			if (pthread_create(&current->thread_id, NULL, &philosopher_routine, philosophers) != 0)
			{
				printf("Failed to create thread for philosopher %d\n", current->index);
				return 1;
			}
			i++;
		}

		// Attendre que tous les threads terminent
		current = philosophers;
		i = 0;
		while (i < num_philosophers)
		{
			if(pthread_join(current->thread_id, NULL) != 0)
			{
				printf("Error join");
			}
			current = current->next;
			i++;
		}

		// Afficher le contenu de chaque nœud de la liste
		current = philosophers;
		i = 0;
		while (i < num_philosophers)
		{
			printf("Philosopher ID: %ld, Index: %d\n", (long)current->thread_id, current->index);
			current = current->next;
			i++;
		}
		
		if(is_pair(num_philosophers) == 0)
		

		// Libérer la mémoire allouée
		current = philosophers;
		t_philosopher *temp;
		i = 0;
		while (i < num_philosophers)
		{
			temp = current;
			current = current->next;
			free(temp);
			i++;
		}
		return 0;
	}
	else
	{
		printf("Usage: %s <number_of_philosophers>\n", av[0]);
		return 1;
	}
} */

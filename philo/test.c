/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:26:02 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/03 17:01:27 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_philosopher {
	int id;
	int left_fork;
	int right_fork;
	long last_meal_time;
	int meals_eaten;
	pthread_t thread_id;
	struct s_data *data;
	pthread_mutex_t meal_time_mutex;  // Mutex pour protéger last_meal_time
} t_philosopher;

typedef struct s_data {
	int num_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_meals;
	int all_alive;
	pthread_mutex_t *forks;
	pthread_mutex_t print_lock;
	pthread_mutex_t alive_lock;  // Mutex pour protéger all_alive
	t_philosopher *philosophers;
} t_data;

// Fonction pour obtenir le temps actuel en millisecondes
long get_time(void) {
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

// Fonction pour afficher les logs en sécurité (éviter les mélanges de messages)
void print_status(t_philosopher *philo, char *status) {
	pthread_mutex_lock(&philo->data->print_lock);
	int alive;
	pthread_mutex_lock(&philo->data->alive_lock);
	alive = philo->data->all_alive;
	pthread_mutex_unlock(&philo->data->alive_lock);
	if (alive) {
		printf("%ld %d %s\n", get_time(), philo->id, status);
	}
	pthread_mutex_unlock(&philo->data->print_lock);
}

// Routine des philosophes
void *philosopher_routine(void *arg) {
	t_philosopher *philo = (t_philosopher *)arg;

	while (1) {
		pthread_mutex_lock(&philo->data->alive_lock);
		if (!philo->data->all_alive) {
			pthread_mutex_unlock(&philo->data->alive_lock);
			break;
		}
		pthread_mutex_unlock(&philo->data->alive_lock);

		// Penser
		print_status(philo, "is thinking");

		// Prendre les fourchettes
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		print_status(philo, "has taken a fork");

		// Manger
		print_status(philo, "is eating");

		pthread_mutex_lock(&philo->meal_time_mutex);
		philo->last_meal_time = get_time();
		pthread_mutex_unlock(&philo->meal_time_mutex);

		usleep(philo->data->time_to_eat * 1000);
		philo->meals_eaten++;

		// Reposer les fourchettes
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);

		// Dormir
		print_status(philo, "is sleeping");
		usleep(philo->data->time_to_sleep * 1000);
	}
	return NULL;
}

// Fonction pour surveiller la mort des philosophes
void *monitor(void *arg) {
	t_data *data = (t_data *)arg;
	int i;

	while (1) {
		i = 0;
		while (i < data->num_philosophers) {
			pthread_mutex_lock(&data->philosophers[i].meal_time_mutex);
			long time_since_last_meal = get_time() - data->philosophers[i].last_meal_time;
			pthread_mutex_unlock(&data->philosophers[i].meal_time_mutex);

			if (time_since_last_meal > data->time_to_die) {
				print_status(&data->philosophers[i], "died");
				pthread_mutex_lock(&data->alive_lock);
				data->all_alive = 0;
				pthread_mutex_unlock(&data->alive_lock);
				return NULL;
			}
			i++;
		}
		usleep(1000); // Vérification toutes les 1ms
	}
	return NULL;
}

// Fonction d'initialisation des philosophes et des fourchettes
void init_data(t_data *data, int argc, char **argv) {
	int i = 0;

	data->num_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->num_meals = (argc == 6) ? ft_atoi(argv[5]) : -1;
	data->all_alive = 1;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
	data->philosophers = malloc(sizeof(t_philosopher) * data->num_philosophers);

	while (i < data->num_philosophers) {
		pthread_mutex_init(&data->forks[i], NULL);
		data->philosophers[i].id = i + 1;
		data->philosophers[i].left_fork = i;
		data->philosophers[i].right_fork = (i + 1) % data->num_philosophers;
		data->philosophers[i].last_meal_time = get_time();
		data->philosophers[i].meals_eaten = 0;
		data->philosophers[i].data = data;
		pthread_mutex_init(&data->philosophers[i].meal_time_mutex, NULL);
		i++;
	}
	pthread_mutex_init(&data->print_lock, NULL);
	pthread_mutex_init(&data->alive_lock, NULL);
}

// Fonction principale
int main(int argc, char **argv) {
	t_data data;
	int i = 0;
	pthread_t monitor_thread;

	if (argc != 5 && argc != 6) {
		printf("nombre d'arguments non valide pour %s\n", argv[0]);
		return 1;
	}

	init_data(&data, argc, argv);

	while (i < data.num_philosophers) {
		pthread_create(&data.philosophers[i].thread_id, NULL, philosopher_routine, &data.philosophers[i]);
		i++;
	}

	pthread_create(&monitor_thread, NULL, monitor, &data);

	i = 0;
	while (i < data.num_philosophers) {
		pthread_join(data.philosophers[i].thread_id, NULL);
		i++;
	}

	pthread_join(monitor_thread, NULL);

	i = 0;
	while (i < data.num_philosophers) {
		pthread_mutex_destroy(&data.forks[i]);
		pthread_mutex_destroy(&data.philosophers[i].meal_time_mutex);
		i++;
	}
	pthread_mutex_destroy(&data.print_lock);
	pthread_mutex_destroy(&data.alive_lock);
	free(data.forks);
	free(data.philosophers);

	return 0;
}

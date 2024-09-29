/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorroy <rcorroy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:58:52 by rcorroy           #+#    #+#             */
/*   Updated: 2024/09/03 16:57:31 by rcorroy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>

typedef struct s_philosopher
{
	int						index;       // Index du philosophe (de 1 à N)
	int 					fork_state;
	int						philo_state;
	pthread_t				thread_id;  // Thread associé au philosophe
	pthread_mutex_t			mutex;
	struct s_philosopher	*next;    // Pointeur vers le philosophe suivant (pour la liste circulaire)
} t_philosopher;

typedef struct s_philosopher {
	int						index;       // Index du philosophe (de 1 à N)
	int left_fork;
	int right_fork;
	long last_meal_time;
	int meals_eaten;
	pthread_t thread_id;
	struct s_philosopher	*next;
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

long	ft_atoi(const char *str);
t_philosopher	*add_philosopher(t_philosopher **head, int index);




#endif
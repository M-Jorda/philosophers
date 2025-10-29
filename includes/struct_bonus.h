/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:00:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/10/29 13:01:15 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>

/* ********************* STRUCTURES BONUS ********************* */

typedef struct s_data_bonus
{
	int						num_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						must_eat_count;
	long					start_time;
	sem_t					*forks_sem;
	sem_t					*print_sem;
	sem_t					*meal_sem;
	sem_t					*death_sem;
	struct s_philo_bonus	*philo;
}	t_data_b;

typedef struct s_philo_bonus
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	pid_t			pid;
	pthread_t		monitor_thread;
	t_data_b		*data;
}	t_philo_b;

/* ********************* NOMS DES SÉMAPHORES ********************* */

# define SEM_FORKS_NAME "/philo_forks"
# define SEM_PRINT_NAME "/philo_print"
# define SEM_MEAL_NAME "/philo_meal"
# define SEM_DEATH_NAME "/philo_death"

#endif

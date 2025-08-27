/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:30:54 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/17 10:59:24 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	volatile int	simulation_end;
	long			start_time;
	pthread_t		monitoring;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	meal_mutex;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo
{
	int			id;
	int			meals_eaten;
	long		last_meal;
	int			l_fork;
	int			r_fork;
	bool		islast;
	pthread_t	thread;
	t_data		*data;
}	t_philo;

#endif
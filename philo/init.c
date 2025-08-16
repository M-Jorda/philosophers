/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:01:02 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/16 09:57:10 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"
#include <sys/time.h>

static inline int	isvalid(t_data *data)
{
	if (data->num_philo == 0)
		return (printerr(WRONG_PHILO, -1));
	if (data->time_to_die == 0)
		return (printerr(WRONG_TTD, -1));
	if (data->time_to_eat == 0)
		return (printerr(WRONG_TTE, -1));
	if (data->time_to_sleep == 0)
		return (printerr(WRONG_TTS, -1));
	return (0);
}

static inline int	init_mutexes(t_data *data)
{
	int	i;

	if (!data)
		return (-1);
	if (pthread_create(data->monitoring, NULL, monitoring, data))
		return (-1);
	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (data->forks == NULL)
		return (-1);
	while (i < data->num_philo)
	{
		if (!pthread_mutex_init(&(data)->forks[i++], NULL))
			return (-1);
	}
	if (!pthread_mutex_init(&(data)->print_mutex, NULL))
		return (-1);
	if (!pthread_mutex_init(&(data)->meal_mutex, NULL))
		return (-1);
}

static inline int	init_philos(t_data *data)
{
	int	i;
	int	size;
	
	if (!data)
		return (-1);
	i = 0;
	size = data->num_philo;
	data->philo = malloc(sizeof(t_philo) * size);
	if (data->philo == NULL)
		return (-1);
	while (i < size)
	{
		data->philo->id = i + 1;
		data->philo->meals_eaten = 0;
		data->philo->last_meal = 0;
		data->philo->l_fork = 0;
		data->philo->r_fork = 0;
		if (pthread_create(&(data)->philo->thread, NULL, routine, data->philo))
			return (-1);
		data->philo->data = data;
	}
	return (0);
}

int	init(t_data *data, int argc, char **argv)
{
	int				i;
	struct timeval	tv;

	if (argc < 3)
		printerr(NOT_ENOUGHT_ARGS, 1);
	else if (argc > 6)
		printerr(TOO_MUCH_ARGS, 1);
	i = 0;
	data->start_time = gettimeofday(&tv, NULL);
	data->simulation_end = 0;
	data->num_philo = ft_atoi(argv[i++]);
	data->time_to_die = ft_atoi(argv[i++]);
	data->time_to_eat = ft_atoi(argv[i++]);
	data->time_to_sleep = ft_atoi(argv[i++]);
	data->must_eat_count = -1;
	if (argv[i])
		data->must_eat_count = argv[i];
	if (!isvalid(data) || !init_mutexes(data) || !init_philos(data))
		return (-1);
	return (0);
}

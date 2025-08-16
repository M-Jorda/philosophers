/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:02:51 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/16 16:13:12 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static inline int	allocate_forks(t_data *data)
{
	if (!data)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (0);
	return (1);
}

static inline int	init_fork_mutexes(t_data *data)
{
	int	num_philo;
	int	res;
	int	i;

	if (!data)
		return (0);
	num_philo = data->num_philo;
	i = 0;
	while (i < num_philo)
	{
		res = pthread_mutex_init(&data->forks[i], NULL);
		if (res != 0)
			return (0);
		i++;
	}
	return (1);
}

static inline int	init_global_mutexes(t_data *data)
{
	int	res;

	if (!data)
		return (0);
	res = pthread_mutex_init(&data->print_mutex, NULL);
	if (res != 0)
		return (0);
	res = pthread_mutex_init(&data->meal_mutex, NULL);
	if (res != 0)
		return (0);
	return (1);
}

int	init_mutexes(t_data *data)
{
	int	status;

	if (!data)
		return (-1);
	status = allocate_forks(data);
	if (!status)
		return (-1);
	status = init_fork_mutexes(data);
	if (!status)
		return (cleanup_forks_mutexes(data));
	status = init_global_mutexes(data);
	if (!status)
		return (cleanup_forks_mutexes(data));
	return (0);
}

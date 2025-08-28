/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:22:55 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/27 21:44:24 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	release_forks(t_philo *philo)
{
	t_data	*data;

	if (!philo)
		return (-1);
	data = philo->data;
	pthread_mutex_unlock(&data->forks[philo->l_fork]);
	pthread_mutex_unlock(&data->forks[philo->r_fork]);
	return (0);
}

static inline int	take_fork(t_philo *philo, int fork)
{
	t_data	*data;

	if (!philo)
		return (0);
	data = philo->data;
	pthread_mutex_lock(&data->forks[fork]);
	if (isfinish(data))
	{
		pthread_mutex_unlock(&data->forks[fork]);
		return (0);
	}
	print_action(philo, FORK);
	return (1);
}

static inline int	one_philo(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->forks[philo->l_fork]);
	print_action(philo, FORK);
	usleep(data->time_to_die * 1000);
	print_action(philo, DIED);
	pthread_mutex_unlock(&data->forks[philo->l_fork]);
	data->simulation_end = 1;
	return (0);
}

int	take_forks(t_philo *philo)
{
	t_data	*data;
	int		status;
	int		first_fork;
	int		second_fork;

	if (!philo)
		return (0);
	data = philo->data;
	if (data->num_philo == 1)
		return ((one_philo(data, philo)));
	first_fork = philo->l_fork;
	second_fork = philo->r_fork;
	if (philo->islast)
	{
		first_fork = philo->r_fork;
		second_fork = philo->l_fork;
	}
	status = take_fork(philo, first_fork);
	if (!status)
		return (status);
	status = take_fork(philo, second_fork);
	if (!status)
		return (status);
	return (1);
}

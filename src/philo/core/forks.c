/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:22:55 by jjorda            #+#    #+#             */
/*   Updated: 2025/10/29 14:32:37 by jjorda           ###   ########.fr       */
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
	if (data->simulation_end)
		return (0);
	pthread_mutex_lock(&data->forks[fork]);
	if (data->simulation_end)
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
	while (!data->simulation_end)
		usleep(1000);
	pthread_mutex_unlock(&data->forks[philo->l_fork]);
	return (0);
}

static void	get_fork_order(t_philo *philo, int *first, int *second)
{
	if (philo->id % 2 == 0)
	{
		*first = philo->l_fork;
		*second = philo->r_fork;
	}
	else
	{
		*first = philo->r_fork;
		*second = philo->l_fork;
	}
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
	if (data->simulation_end)
		return (0);
	if (data->num_philo == 1)
		return ((one_philo(data, philo)));
	get_fork_order(philo, &first_fork, &second_fork);
	status = take_fork(philo, first_fork);
	if (!status)
		return (status);
	status = take_fork(philo, second_fork);
	if (!status)
	{
		pthread_mutex_unlock(&data->forks[first_fork]);
		return (status);
	}
	return (1);
}

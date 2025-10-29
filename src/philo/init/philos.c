/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:42:50 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/28 11:49:43 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline int	alloc_philos(t_data *data)
{
	size_t	size;

	if (!data)
		return (0);
	size = data->num_philo * sizeof(t_philo);
	data->philo = malloc(size);
	if (!data->philo)
		return (0);
	memset(data->philo, 0, size);
	return (1);
}

static int	init_each_philo(t_data *data, int index)
{
	t_philo	*philo;
	int		res;

	if (!data || index < 0)
		return (0);
	philo = &data->philo[index];
	philo->id = index + 1;
	philo->meals_eaten = 0;
	philo->l_fork = index;
	philo->r_fork = (index + 1) % data->num_philo;
	philo->data = data;
	philo->islast = false;
	if (index == data->num_philo - 1)
		philo->islast = true;
	res = pthread_create(&philo->thread, NULL, routine, philo);
	if (res != 0)
		return (0);
	return (1);
}

int	init_philos(t_data *data)
{
	int	num_philo;
	int	status;
	int	i;

	if (!data || !alloc_philos(data))
		return (0);
	i = 0;
	num_philo = data->num_philo;
	while (i < num_philo)
	{
		status = init_each_philo(data, i);
		if (!status)
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:48:14 by jjorda            #+#    #+#             */
/*   Updated: 2025/10/29 12:33:53 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static inline int	alloc_philos_b(t_data_b *data)
{
	size_t	size;

	if (!data)
		return (0);
	size = data->num_philo * sizeof(t_philo_b);
	data->philo = malloc(size);
	if (!data->philo)
		return (0);
	memset(data->philo, 0, size);
	return (1);
}

static int	init_each_philo_b(t_data_b *data, int index)
{
	t_philo_b	*philo;

	if (!data || index < 0)
		return (0);
	philo = &data->philo[index];
	philo->id = index + 1;
	philo->meals_eaten = 0;
	philo->last_meal = 0;
	philo->pid = -1;
	philo->monitor_thread = 0;
	philo->data = data;
	return (1);
}

int	init_philos_b(t_data_b *data)
{
	int	num_philo;
	int	status;
	int	i;

	if (!data || !alloc_philos_b(data))
		return (0);
	i = 0;
	num_philo = data->num_philo;
	while (i < num_philo)
	{
		status = init_each_philo_b(data, i);
		if (!status)
			return (0);
		i++;
	}
	return (1);
}

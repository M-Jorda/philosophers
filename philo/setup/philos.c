/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:42:50 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/16 17:38:38 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static inline int	alloc_philos(t_data *data)
{
	if (!data)
		return (1);
	data->philo = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philo)
		return (1);
	return (0);
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
	philo->last_meal = data->start_time;
	philo->l_fork = index;
	philo->r_fork = (index + 1) % data->num_philo;
	philo->data = data;
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

	if (!data || alloc_philos(data))
		return (-1);
	i = 0;
	num_philo = data->num_philo;
	while (i < num_philo)
	{
		status = init_each_philo(data, i);
		if (!status)
			return (-1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:44:09 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/27 14:35:29 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static bool haseaten_enought(t_data *data)
{
	t_philo *philo;
	int i;

	if (!data)
		return (false);
	if (data->must_eat_count == -1)
		return (false);
	philo = data->philo;
	i = 0;
	while (i < data->num_philo)
	{
		if (philo[i].meals_eaten < data->must_eat_count)
			return (false);
		i++;
	}
	return (true);
}

static bool is_philo_dead(t_data *data)
{
	int i;
	long now;

	if (!data)
		return (false);
	now = get_elapsed_time(data);
	for (i = 0; i < data->num_philo; i++)
	{
		pthread_mutex_lock(&data->meal_mutex);
		if ((now - data->philo[i].last_meal) > data->time_to_die)
		{
			pthread_mutex_unlock(&data->meal_mutex);
			return (true);
		}
		pthread_mutex_unlock(&data->meal_mutex);
	}
	return (false);
}

bool isfinish(t_data *data)
{
	if (!data)
		return (true);
	if (is_philo_dead(data))
		return (true);
	if (haseaten_enought(data))
		return (true);
	if (data.)
	return (false);
}

void *monitoring(void *arg)
{
	t_data *data;

	if (!arg)
		return (NULL);
	data = (t_data *) arg;
	while (!data->simulation_end)
	{
		if (isfinish(data))
			data->simulation_end = 1;
		usleep(1000); // Pause pour éviter 100% CPU
	}
	return ((void *) data);
}

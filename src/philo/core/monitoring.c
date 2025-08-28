/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:44:09 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/27 21:48:02 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	haseaten_enought(t_data *data)
{
	t_philo	*philo;
	int		i;
	int		total_meals;
	int		current_meals;

	if (!data)
		return (false);
	if (data->must_eat_count == -1)
		return (false);
	philo = data->philo;
	i = 0;
	total_meals = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_lock(&data->meal_mutex);
		current_meals = philo[i].meals_eaten;
		pthread_mutex_unlock(&data->meal_mutex);
		if (current_meals < data->must_eat_count)
			return (false);
		total_meals += current_meals;
		i++;
	}
	return (total_meals >= data->num_philo * data->must_eat_count);
}

static bool	is_philo_dead(t_data *data)
{
	int		i;
	long	now;

	if (!data)
		return (false);
	now = get_elapsed_time(data);
	i = -1;
	while (++i < data->num_philo)
	{
		pthread_mutex_lock(&data->meal_mutex);
		if ((now - data->philo[i].last_meal) > data->time_to_die)
		{
			pthread_mutex_unlock(&data->meal_mutex);
			print_action(&data->philo[i], DIED);
			pthread_mutex_lock(&data->print_mutex);
			data->simulation_end = 1;
			pthread_mutex_unlock(&data->print_mutex);
			return (true);
		}
		pthread_mutex_unlock(&data->meal_mutex);
	}
	return (false);
}

bool	isfinish(t_data *data)
{
	if (!data)
		return (true);
	if (is_philo_dead(data))
		return (true);
	if (haseaten_enought(data))
		return (true);
	return (false);
}

void	*monitoring(void *arg)
{
	t_data	*data;

	if (!arg)
		return (NULL);
	data = (t_data *) arg;
	while (!data->simulation_end)
	{
		if (isfinish(data))
		{
			pthread_mutex_lock(&data->print_mutex);
			data->simulation_end = 1;
			pthread_mutex_unlock(&data->print_mutex);
		}
	}
	return ((void *) data);
}

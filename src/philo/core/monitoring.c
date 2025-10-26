/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:44:09 by jjorda            #+#    #+#             */
/*   Updated: 2025/10/26 20:35:01 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_philo_meals(t_data *data, int i)
{
	int	current_meals;

	pthread_mutex_lock(&data->meal_mutex);
	current_meals = data->philo[i].meals_eaten;
	pthread_mutex_unlock(&data->meal_mutex);
	if (current_meals < data->must_eat_count)
		return (false);
	return (true);
}

static bool	haseaten_enought(t_data *data)
{
	int		i;

	if (!data)
		return (false);
	if (data->must_eat_count == -1)
		return (false);
	i = 0;
	while (i < data->num_philo)
	{
		if (!check_philo_meals(data, i))
			return (false);
		i++;
	}
	return (true);
}

static bool	is_philo_dead(t_data *data)
{
	int		i;
	long	now;
	long	time_since_meal;

	if (!data)
		return (false);
	i = -1;
	while (++i < data->num_philo)
	{
		now = get_elapsed_time(data);
		pthread_mutex_lock(&data->meal_mutex);
		time_since_meal = now - data->philo[i].last_meal;
		pthread_mutex_unlock(&data->meal_mutex);
		if (time_since_meal > data->time_to_die)
		{
			pthread_mutex_lock(&data->print_mutex);
			data->simulation_end = 1;
			printf("%ld %d %s\n", now, data->philo[i].id, DIED);
			pthread_mutex_unlock(&data->print_mutex);
			return (true);
		}
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
		if (is_philo_dead(data))
			break ;
		if (haseaten_enought(data))
		{
			pthread_mutex_lock(&data->print_mutex);
			data->simulation_end = 1;
			pthread_mutex_unlock(&data->print_mutex);
			break ;
		}
		usleep(1000);
	}
	return ((void *) data);
}

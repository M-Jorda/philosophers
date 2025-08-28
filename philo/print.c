/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:26:44 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/27 21:45:16 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	print_action(t_philo *philo, char *action)
{
	t_data	*data;
	long	timestamp;

	if (!philo || !action)
		return (-1);
	data = philo->data;
	pthread_mutex_lock(&data->print_mutex);
	if (data->simulation_end)
	{
		pthread_mutex_unlock(&data->print_mutex);
		return (-1);
	}
	timestamp = get_elapsed_time(data);
	printf("%ld %d %s\n", timestamp, philo->id, action);
	pthread_mutex_unlock(&data->print_mutex);
	return (0);
}

int	print_death(t_philo *philo)
{
	t_data	*data;

	if (!philo)
		return (-1);
	data = philo->data;
	pthread_mutex_lock(&data->print_mutex);
	data->simulation_end = 1;
	printf("%ld %d %s\n", get_elapsed_time(data), philo->id, DIED);
	pthread_mutex_unlock(&data->print_mutex);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:26:44 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/18 08:55:18 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	print_action(t_philo *philo, char *action)
{
	t_data *data;
	long	timestamp;

	if (!philo || !action)
		return (-1);
//	debug("print_action", 0);
	data = philo->data;
//	debug("print_action", 1);
	pthread_mutex_lock(&data->print_mutex);
	if (data->simulation_end)
	{
		pthread_mutex_unlock(&data->print_mutex);
		return (-1);
	}
//	debug("print_action", 3);
	timestamp = get_elapsed_time(data);
//	debug("print_action", 4);
	printf("%ld %d %s\n", timestamp, philo->id, action);
//	debug("print_action", 5);
	pthread_mutex_unlock(&data->print_mutex);
	return (0);
}

int	print_death(t_philo *philo)
{
	t_data	*data;

	if (!philo)
		return (-1);
	data = philo->data;
	data->simulation_end = 1;
	pthread_mutex_lock(&data->print_mutex);
	print_action(philo, DIED);
	pthread_mutex_unlock(&data->print_mutex);
	return (0);
}

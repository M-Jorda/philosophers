/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:44:59 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/18 08:55:18 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"
 

int	is_eating(t_philo *philo)
{
	t_data	*data;
	long	curr_time;
	int		status;

	if (!philo)
		return (-1);
	data = philo->data;
	status = take_forks(philo);
	if (!status)
		return (-1);
//	debug("is_eating", -1);
	pthread_mutex_lock(&data->meal_mutex);
//	debug("is_eating", 0);
	curr_time = get_elapsed_time(data);
//	debug("is_eating", 1);
	philo->last_meal = curr_time;
	philo->meals_eaten++;
//	debug("is_eating", 2);
	if (print_action(philo, EAT) == -1)
		return (-1);
//	debug("is_eating", 3);
	pthread_mutex_unlock(&data->meal_mutex);
//	debug("is_eating", 4);
	usleep(data->time_to_eat * 1000);
//	debug("is_eating", 5);
	release_forks(philo);
//	debug("is_eating", 6);
	return (0);
}

static inline int	is_sleeping(t_philo *philo)
{
	t_data	*data;

	if (!philo)
		return (-1);
	if (!print_action(philo, SLEEP))
		return (-1);
	data = philo->data;
	usleep(data->time_to_sleep * 1000);
	return (0);
}

static inline int	is_thinking(t_philo *philo)
{
	if (!philo)
		return (-1);
	if (!print_action(philo, THINK))
		return (-1);
	return (0);
}

void	*routine(void *arg)
{
	t_philo			*philo;

	if (!arg)
		return (NULL);
	philo = (t_philo *) arg;
//	debug("routine", -1);
	
	// BOUCLE pour éviter que le thread termine immédiatement
	while (!philo->data->simulation_end)
	{
		if (is_eating(philo))
			break;
	//	debug("routine", 0);
		if (is_sleeping(philo))
			break;
	//	debug("routine", 1);
		if (is_thinking(philo))
			break;
	//	debug("routine", 3);
		
		// Petite pause pour éviter CPU intensif
		usleep(1000);
	}
	return ((void *) philo);
}

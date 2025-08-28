/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:44:59 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/27 21:45:42 by jjorda           ###   ########.fr       */
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
	if (data->simulation_end)
		return (-1);
	status = take_forks(philo);
	if (!status)
		return (-1);
	pthread_mutex_lock(&data->meal_mutex);
	curr_time = get_elapsed_time(data);
	philo->last_meal = curr_time;
	philo->meals_eaten++;
	if (print_action(philo, EAT) == -1)
		return (-1);
	pthread_mutex_unlock(&data->meal_mutex);
	usleep(data->time_to_eat * 1000);
	release_forks(philo);
	return (0);
}

static int	is_sleeping(t_philo *philo)
{
	t_data	*data;

	if (!philo)
		return (-1);
	if (print_action(philo, SLEEP))
		return (-1);
	data = philo->data;
	usleep(data->time_to_sleep * 1000);
	return (0);
}

static int	is_thinking(t_philo *philo)
{
	if (!philo)
		return (-1);
	if (print_action(philo, THINK))
		return (-1);
	usleep(1000);
	return (0);
}

void	*routine(void *arg)
{
	t_philo			*philo;
	int				should_continue;

	if (!arg)
		return (NULL);
	philo = (t_philo *) arg;
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal = philo->data->start_time;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	pthread_mutex_lock(&philo->data->print_mutex);
	should_continue = !philo->data->simulation_end;
	pthread_mutex_unlock(&philo->data->print_mutex);
	while (should_continue)
	{
		if (is_eating(philo) == -1)
			break ;
		if (is_sleeping(philo))
			break ;
		if (is_thinking(philo))
			break ;
		pthread_mutex_lock(&philo->data->print_mutex);
		should_continue = !philo->data->simulation_end;
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
	return ((void *) philo);
}

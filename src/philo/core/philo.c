/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:44:59 by jjorda            #+#    #+#             */
/*   Updated: 2025/10/29 11:53:18 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	loop_until(t_data *data, long end)
{
	while (get_elapsed_time(data) < end)
	{
		if (data->simulation_end)
			return (false);
		usleep(20);
	}
	return (true);
}

int	is_eating(t_philo *philo)
{
	t_data	*data;
	int		status;
	long	eat_until;

	if (!philo)
		return (-1);
	data = philo->data;
	if (data->simulation_end)
		return (-1);
	status = take_forks(philo);
	if (!status)
		return (-1);
	pthread_mutex_lock(&data->meal_mutex);
	philo->last_meal = get_elapsed_time(data);
	philo->meals_eaten++;
	pthread_mutex_unlock(&data->meal_mutex);
	print_action(philo, EAT);
	eat_until = get_elapsed_time(data) + data->time_to_eat;
	loop_until(data, eat_until);
	// while (get_elapsed_time(data) < eat_until)
	// {
	// 	if (data->simulation_end)
	// 		break ;
	// 	usleep(20);
	// }
	release_forks(philo);
	return (0);
}

static int	is_sleeping(t_philo *philo)
{
	t_data	*data;
	long	wake_time;

	if (!philo)
		return (-1);
	data = philo->data;
	if (data->simulation_end)
		return (-1);
	print_action(philo, SLEEP);
	wake_time = get_elapsed_time(data) + data->time_to_sleep;
	if (!loop_until(data, wake_time))
		return (-1);
	// while (get_elapsed_time(data) < wake_time)
	// {
	// 	if (data->simulation_end)
	// 		return (-1);
	// 	usleep(20);
	// }
	return (0);
}

static int	is_thinking(t_philo *philo)
{
	t_data	*data;
	int		think_time;
	long	think_until;

	if (!philo)
		return (-1);
	data = philo->data;
	if (data->simulation_end)
		return (-1);
	print_action(philo, THINK);
	if (data->num_philo % 2 == 1)
	{
		think_time = (data->time_to_eat * 2) - data->time_to_sleep;
		if (think_time > 0 && think_time < 600)
		{
			think_until = get_elapsed_time(data) + think_time;
			if (!loop_until(data, think_until))
				return (-1);
			// while (get_elapsed_time(data) < think_until)
			// {
			// 	if (data->simulation_end)
			// 		return (-1);
			// 	usleep(20);
			// }
			return (0);
		}
	}
	usleep(20);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	if (!arg)
		return (NULL);
	philo = (t_philo *) arg;
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal = get_elapsed_time(philo->data);
	pthread_mutex_unlock(&philo->data->meal_mutex);
	if (philo->id % 2 == 1 && philo->data->num_philo > 1)
		usleep(philo->data->time_to_eat * 500);
	while (!check_simulation_end(philo->data))
	{
		if (is_eating(philo) == -1)
			break ;
		if (is_sleeping(philo) == -1)
			break ;
		if (is_thinking(philo) == -1)
			break ;
	}
	return ((void *) philo);
}

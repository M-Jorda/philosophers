/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:06:09 by jjorda            #+#    #+#             */
/*   Updated: 2025/10/29 19:35:21 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_eating_b(t_philo_b *philo)
{
	t_data_b	*data;
	long		curr_time;

	if (!philo)
		return (-1);
	data = philo->data;
	sem_wait(philo->data->meal_sem);
	curr_time = get_elapsed_time(data);
	philo->last_meal = curr_time;
	philo->meals_eaten++;
	sem_post(philo->data->meal_sem);
	if (print_action_b(philo, EAT) == -1)
		return (-1);
	ft_wait(data->time_to_eat, data);
	return (0);
}

static int	is_sleeping_b(t_philo_b *philo)
{
	if (!philo)
		return (-1);
	if (print_action_b(philo, SLEEP))
		return (-1);
	ft_wait(philo->data->time_to_sleep, philo->data);
	return (0);
}

static int	is_thinking_b(t_philo_b *philo)
{
	if (!philo)
		return (-1);
	if (print_action_b(philo, THINK))
		return (-1);
	return (0);
}

static void	init_routine_b(t_philo_b *philo)
{
	sem_wait(philo->data->meal_sem);
	if (philo->data->num_philo == 1)
		philo->last_meal = 0;
	else
		philo->last_meal = get_elapsed_time(philo->data);
	sem_post(philo->data->meal_sem);
	pthread_create(&philo->monitor_thread, NULL, monitoring_b, philo);
	pthread_detach(philo->monitor_thread);
	usleep(100);
	if (philo->data->num_philo == 1)
	{
		print_action_b(philo, FORK);
		while (1)
			usleep(1000);
	}
	if (philo->id % 2 == 1)
		usleep((philo->data->time_to_eat / 2) * 1000);
}

void	routine_b(t_philo_b *philo)
{
	int			must_eat;

	if (!philo)
		return ;
	must_eat = philo->data->must_eat_count;
	init_routine_b(philo);
	while (1)
	{
		take_forks_b(philo);
		is_eating_b(philo);
		release_forks_b(philo);
		if (must_eat > 0 && philo->meals_eaten >= must_eat)
		{
			cleanup_child_b(philo->data);
			exit(EXIT_SUCCESS_FED);
		}
		is_sleeping_b(philo);
		is_thinking_b(philo);
	}
	cleanup_child_b(philo->data);
	exit(EXIT_ERROR);
}

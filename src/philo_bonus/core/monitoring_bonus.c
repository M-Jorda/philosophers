/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:00:16 by jjorda            #+#    #+#             */
/*   Updated: 2025/10/26 20:35:02 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitoring_b(void *arg)
{
	t_philo_b	*philo;
	long		time_last_meal;

	if (!arg)
		return (NULL);
	philo = (t_philo_b *) arg;
	while (1)
	{
		sem_wait(philo->data->meal_sem);
		time_last_meal = get_elapsed_time(philo->data) - philo->last_meal;
		sem_post(philo->data->meal_sem);
		if (time_last_meal > philo->data->time_to_die)
		{
			print_death_b(philo);
			exit(EXIT_DEATH);
		}
		usleep(1000);
	}
	return (NULL);
}

void	monitor_process(t_data_b *data)
{
	int		status;
	int		philo_feed;

	if (!data)
		return ;
	philo_feed = 0;
	while (philo_feed < data->num_philo)
	{
		wait(&status);
		if (WEXITSTATUS(status) == EXIT_DEATH)
		{
			kill_philos(data, -1);
			return ;
		}
		else if (WEXITSTATUS(status) == EXIT_SUCCESS_FED)
			philo_feed++;
	}
}

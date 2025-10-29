/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:52:07 by jjorda            #+#    #+#             */
/*   Updated: 2025/09/02 16:17:23 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	clean_sem_b(sem_t *semaphore, char *NAME)
{
	sem_close(semaphore);
	sem_unlink(NAME);
}

int	cleanup_b(t_data_b *data, int err)
{
	if (!data)
		return (1);
	if (data->forks_sem != SEM_FAILED)
		clean_sem_b(data->forks_sem, SEM_FORKS_NAME);
	if (data->print_sem != SEM_FAILED)
		clean_sem_b(data->print_sem, SEM_PRINT_NAME);
	if (data->meal_sem != SEM_FAILED)
		clean_sem_b(data->meal_sem, SEM_MEAL_NAME);
	if (data->death_sem != SEM_FAILED)
		clean_sem_b(data->death_sem, SEM_DEATH_NAME);
	if (data->philo)
		free(data->philo);
	return (err);
}

void	kill_philos(t_data_b *data, int index)
{
	t_philo_b	*philo;
	int			tot_philo;
	int			i;

	if (!data)
		return ;
	i = -1;
	tot_philo = data->num_philo;
	while (++i < tot_philo)
	{
		philo = &data->philo[i];
		if (i != index && philo->pid > 0)
			kill(philo->pid, SIGTERM);
	}
}

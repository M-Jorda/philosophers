/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:48:36 by jjorda            #+#    #+#             */
/*   Updated: 2025/09/02 16:17:14 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static inline void	sem_unlink_b(void)
{
	sem_unlink(SEM_FORKS_NAME);
	sem_unlink(SEM_PRINT_NAME);
	sem_unlink(SEM_MEAL_NAME);
}

int	init_semaphores_b(t_data_b *data)
{
	if (!data)
		return (0);
	sem_unlink_b();
	data->forks_sem = sem_open(SEM_FORKS_NAME, O_CREAT | O_EXCL, 0644,
			data->num_philo);
	if (data->forks_sem == SEM_FAILED)
		return (printerr(SEM_FAILED_MSG, 0));
	data->print_sem = sem_open(SEM_PRINT_NAME, O_CREAT | O_EXCL, 0644, 1);
	if (data->print_sem == SEM_FAILED)
	{
		cleanup_b(data, 1);
		return (printerr(SEM_FAILED_MSG, 0));
	}
	data->meal_sem = sem_open(SEM_MEAL_NAME, O_CREAT | O_EXCL, 0644, 1);
	if (data->meal_sem == SEM_FAILED)
	{
		cleanup_b(data, 1);
		return (printerr(SEM_FAILED_MSG, 0));
	}
	return (1);
}

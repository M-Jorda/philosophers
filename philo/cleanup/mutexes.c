/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:10:13 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/16 16:15:51 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

int	cleanup_forks_mutexes(t_data *data)
{
	int	forks_count;
	int	i;

	forks_count = data->num_philo;
	i = 0;
	while (i < forks_count)
	{
		if (&data->forks[i])
			pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	if (data->forks)
		free(data->forks);
	return (-1);
}

static inline void	cleanup_glogal_mutexes(t_data *data)
{
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
}

void	cleanup_mutexes(t_data *data)
{
	cleanup_forks_mutexes(data);
	cleanup_glogal_mutexes(data);
	if (data->forks)
		free(data->forks);
}

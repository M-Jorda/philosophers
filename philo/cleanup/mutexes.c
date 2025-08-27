/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:10:13 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/16 18:54:22 by jjorda           ###   ########.fr       */
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
		pthread_mutex_destroy(&data->forks[i]);
		i++;
		// free(&data->forks[i]);
	}
	// if (data->forks)
	free(data->forks);
	return (0);
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
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:16:11 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/16 17:47:35 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static void	cleanup_each_philo(t_data *data, int index)
{
	t_philo	*philo;

	philo = &data->philo[index];
	pthread_detach(philo->thread);
}

void	cleanup_philos(t_data *data)
{
	int	num_philo;
	int	i;

	num_philo = data->num_philo;
	i = 0;
	while (i < num_philo)
	{
		cleanup_each_philo(data, i);
		i++;
	}
	if (data->philo)
		free(data->philo);
}

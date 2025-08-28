/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:16:11 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/28 09:21:43 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

static void	cleanup_each_philo(t_data *data, int index)
{
	t_philo	*philo;

	if (!data || index < 0 || index >= data->num_philo)
		return ;
	philo = &data->philo[index];
	pthread_join(philo->thread, NULL);
}

void	cleanup_philos(t_data *data)
{
	int	num_philo;
	int	i;

	if (!data)
		return ;
	num_philo = data->num_philo;
	i = 0;
	while (i < num_philo)
	{
		cleanup_each_philo(data, i);
		i++;
	}
	if (data->philo)
	{
		free(data->philo);
		data->philo = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_philos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:26:56 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/27 21:50:36 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_info_philo(t_philo philo)
{
	printf("\nid: %d\n", philo.id);
	printf("meals_eaten: %d\n", philo.meals_eaten);
	printf("last_meal: %ld\n", philo.last_meal);
	printf("l_fork: %d\n", philo.l_fork);
	printf("r_fork: %d\n", philo.r_fork);
	printf("islast: %d\n", philo.islast);
}

void	debug_philos(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = data->philo;
	i = -1;
	while (++i < data->num_philo)
		print_info_philo(philo[i]);
	printf("\n");
}

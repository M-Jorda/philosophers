/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_philos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:26:56 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/17 11:04:11 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

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
	t_philo *philo;
	int		i;

	philo = data->philo;
	i = 0;
	// printf("%d\n", data->num_philo);
	while (i < data->num_philo)
	{
		print_info_philo(philo[i]);
		i++;
	}
	printf("\n");
}

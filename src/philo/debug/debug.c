/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:36:08 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/28 09:57:59 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	debug_data(t_data *data)
{
	printf("DEBUG: Number of Philo : %d\n", data->num_philo);
	printf("DEBUG: Time to die : %d\n", data->time_to_die);
	printf("DEBUG: Time to eat : %d\n", data->time_to_eat);
	printf("DEBUG: Time to sleep : %d\n", data->time_to_sleep);
	printf("DEBUG: Time must eat : %d\n", data->must_eat_count);
	printf("DEBUG: Start time : %ld\n", data->start_time);
}

void	debug(char *mess, int num)
{
	printf("DEBUG: %s/%d\n", mess, num);
}

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

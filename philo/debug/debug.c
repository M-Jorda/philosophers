/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:36:08 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/18 08:51:55 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

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
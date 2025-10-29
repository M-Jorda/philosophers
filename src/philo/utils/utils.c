/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:39:30 by jjorda            #+#    #+#             */
/*   Updated: 2025/10/29 13:01:15 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	calculate_msec(void)
{
	struct timeval	tv;
	long			sec;
	long			msec;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	if (tv.tv_sec < 0 || tv.tv_usec >= 1000000)
		return (-1);
	sec = tv.tv_sec * 1000;
	msec = tv.tv_usec / 1000;
	return (sec + msec);
}

long	get_elapsed_time(t_data *data)
{
	long	curr_time;
	long	elapsed;

	if (!data)
		return (-1);
	curr_time = calculate_msec();
	if (curr_time == -1)
		return (-1);
	elapsed = curr_time - data->start_time;
	if (elapsed < 0)
		return (0);
	return (elapsed);
}

int	check_simulation_end(t_data *data)
{
	int	result;

	if (!data)
		return (1);
	pthread_mutex_lock(&data->print_mutex);
	result = data->simulation_end;
	pthread_mutex_unlock(&data->print_mutex);
	return (result);
}

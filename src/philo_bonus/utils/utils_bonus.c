/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:39:30 by jjorda            #+#    #+#             */
/*   Updated: 2025/10/29 13:01:15 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

long	get_elapsed_time(t_data_b *data)
{
	long	curr_time;

	if (!data)
		return (-1);
	curr_time = calculate_msec();
	if (curr_time == -1)
		return (-1);
	return (curr_time - data->start_time);
}

void	ft_wait(long duration_ms, t_data_b *data)
{
	long	start;
	long	current;

	if (!data || duration_ms <= 0)
		return ;
	start = get_elapsed_time(data);
	while (1)
	{
		current = get_elapsed_time(data);
		if (current - start >= duration_ms)
			break ;
		usleep(20);
	}
}

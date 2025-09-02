/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:39:30 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/28 12:05:58 by jjorda           ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;
	int	digit;

	if (!str)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		result = result * 10 + digit;
		i++;
	}
	return (result * sign);
}

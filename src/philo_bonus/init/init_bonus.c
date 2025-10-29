/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:44:15 by jjorda            #+#    #+#             */
/*   Updated: 2025/10/29 15:01:12 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void iserr(t_data_b *data, char *err_mess)
{
	(void) data;
	printerr(err_mess, 1);
}

static inline int	isvalid(t_data_b *data)
{
	if (data->num_philo <= 0)
		iserr(data, WRONG_PHILO);
	if (data->time_to_die <= 0)
		iserr(data, WRONG_TTD);
	if (data->time_to_eat <= 0)
		iserr(data, WRONG_TTE);
	if (data->time_to_sleep <= 0)
		iserr(data, WRONG_TTS);
	if (data->must_eat_count < -1)
		iserr(data, WRONG_MEAL_COUNT);
	return (1);
}

int	init_b(t_data_b *data, char **argv)
{
	int	i;

	if (!data)
		return (-1);
	i = 0;
	data->start_time = calculate_msec();
	if (data->start_time < 0)
		return (-1);
	data->num_philo = ft_atoi(argv[i++]);
	data->time_to_die = ft_atoi(argv[i++]);
	data->time_to_eat = ft_atoi(argv[i++]);
	data->time_to_sleep = ft_atoi(argv[i++]);
	data->must_eat_count = -1;
	if (argv[i])
		data->must_eat_count = ft_atoi(argv[i]);
	if (!isvalid(data))
		return (-1);
	if (!init_semaphores_b(data))
		return (-1);
	if (!init_philos_b(data))
		return (-1);
	return (0);
}

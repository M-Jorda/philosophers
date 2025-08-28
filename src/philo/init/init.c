/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:01:02 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/27 16:28:46 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline int	isvalid(t_data *data)
{
	if (data->num_philo == 0)
		return (printerr(WRONG_PHILO, -1));
	if (data->time_to_die == 0)
		return (printerr(WRONG_TTD, -1));
	if (data->time_to_eat == 0)
		return (printerr(WRONG_TTE, -1));
	if (data->time_to_sleep == 0)
		return (printerr(WRONG_TTS, -1));
	if (data->must_eat_count == 0)
		return (printerr(WRONG_MEAL_COUNT, -1));
	return (1);
}

int	init(t_data *data, char **argv)
{
	int				i;

	if (!data)
		return (-1);
	i = 0;
	data->start_time = calculate_msec();
	if (data->start_time < 0)
		return (-1);
	data->simulation_end = 0;
	data->num_philo = ft_atoi(argv[i++]);
	data->time_to_die = ft_atoi(argv[i++]);
	data->time_to_eat = ft_atoi(argv[i++]);
	data->time_to_sleep = ft_atoi(argv[i++]);
	data->must_eat_count = -1;
	if (argv[i])
		data->must_eat_count = ft_atoi(argv[i]);
	if (!isvalid(data))
		return (-1);
	if (!init_mutexes(data))
		return (-1);
	if (!init_philos(data))
		return (-1);
	if (pthread_create(&data->monitoring, NULL, monitoring, data) != 0)
		return (-1);
	return (0);
}

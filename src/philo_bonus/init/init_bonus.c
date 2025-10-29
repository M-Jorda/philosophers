/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:44:15 by jjorda            #+#    #+#             */
/*   Updated: 2025/10/29 12:33:53 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static inline int	isvalid(t_data_b *data)
{
	if (data->num_philo < 0)
		return (printerr("Error: Invalid number of philosophers\n", 0));
	if (data->time_to_die < 0)
		return (printerr("Error: Invalid time_to_die\n", 0));
	if (data->time_to_eat < 0)
		return (printerr("Error: Invalid time_to_eat\n", 0));
	if (data->time_to_sleep < 0)
		return (printerr("Error: Invalid time_to_sleep\n", 0));
	if (data->must_eat_count < -1)
		return (printerr("Error: Invalid must_eat_count\n", 0));
	if (data->num_philo == 0)
		return (printerr(WRONG_PHILO, 0));
	if (data->time_to_die == 0)
		return (printerr(WRONG_TTD, 0));
	if (data->time_to_eat == 0)
		return (printerr(WRONG_TTE, 0));
	if (data->time_to_sleep == 0)
		return (printerr(WRONG_TTS, 0));
	if (data->must_eat_count == 0)
		return (printerr(WRONG_MEAL_COUNT, 0));
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

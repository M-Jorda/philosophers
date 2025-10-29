/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:28:08 by jjorda            #+#    #+#             */
/*   Updated: 2025/10/29 14:57:12 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static inline void	validate_args_b(int argc, char **argv)
{
	if (argc < 5)
		printerr(NOT_ENOUGHT_ARGS, 1);
	else if (argc > 6)
		printerr(TOO_MUCH_ARGS, 1);
	else if (argv[1][0] == '0')
		printerr(ZERO_PHILO, 1);
}

static inline int	start_simulation_b(t_data_b *data)
{
	t_philo_b	*philo;
	int			num_philo;
	int			i;

	if (!data)
		return (-1);
	data->start_time = calculate_msec();
	i = -1;
	num_philo = data->num_philo;
	while (++i < num_philo)
	{
		philo = &data->philo[i];
		philo->pid = fork();
		if (philo->pid == 0)
			routine_b(philo);
		else if (philo->pid < 0)
		{
			kill_philos(data, i);
			return (printerr(FORK_FAILED_MSG, -1));
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data_b	data;

	validate_args_b(argc, argv);
	if (init_b(&data, &argv[1]) != 0)
		return (cleanup_b(&data, 1));
	if (start_simulation_b(&data))
		return (cleanup_b(&data, 1));
	monitor_process(&data);
	return (cleanup_b(&data, 0));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:49:24 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/28 09:54:02 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline void	validate_args(int argc)
{
	if (argc < 5)
		printerr(NOT_ENOUGHT_ARGS, 1);
	else if (argc > 6)
		printerr(TOO_MUCH_ARGS, 1);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		status;

	(void) env;
	validate_args(argc);
	status = init(&data, &argv[1]);
	if (status != 0)
	{
		printerr("Error: init failed\n", 1);
		return (1);
	}
	pthread_join(data.monitoring, NULL);
	cleanup_total(&data);
	return (0);
}

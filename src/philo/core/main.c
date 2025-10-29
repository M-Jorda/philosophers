/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:49:24 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/28 11:29:05 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline int	validate_args(int argc)
{
	if (argc < 5)
		return (printerr(NOT_ENOUGHT_ARGS, 1));
	else if (argc > 6)
		return (printerr(TOO_MUCH_ARGS, 1));
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		status;

	status = validate_args(argc);
	if (status != 0)
		return (status);
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

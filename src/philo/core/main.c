/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:49:24 by jjorda            #+#    #+#             */
/*   Updated: 2025/10/29 14:53:16 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline int	validate_args(int argc, char **argv)
{
	if (argc < 5)
		return (printerr(NOT_ENOUGHT_ARGS, 1));
	else if (argc > 6)
		return (printerr(TOO_MUCH_ARGS, 1));
	else if (argv[1][0] == '0')
		return (printerr(ZERO_PHILO, 1));
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		status;

	status = validate_args(argc, argv);
	if (status != 0)
		return (status);
	status = init(&data, &argv[1]);
	if (status != 0)
		return (1);
	pthread_join(data.monitoring, NULL);
	cleanup_total(&data);
	return (0);
}

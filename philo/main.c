/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:49:24 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/16 16:04:59 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static inline void	validate_args(int argc, char **argv)
{
	if (argc < 5)
		printerr(NOT_ENOUGHT_ARGS, 1);
	else if (argc > 6)
		printerr(TOO_MUCH_ARGS, 1);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void) env;
	validate_args(argc, argv);
	init(&data, &argv[1]);
}
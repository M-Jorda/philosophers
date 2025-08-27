/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:49:24 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/18 08:58:55 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

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

	(void) env;
	validate_args(argc);
	// printf("DEBUG: main 01\n");
	init(&data, &argv[1]);
	// debug_data(&data);
	// printf("DEBUG: main 02\n");
	// debug_philos(&data);
	
	// AJOUT: Signaler l'arrêt aux threads
	usleep(100000); // Laisser les threads démarrer
	// data.simulation_end = 1; // Signal d'arrêt
	
	cleanup_total(&data);
	return (0);
}

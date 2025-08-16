/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:47:40 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/16 17:45:41 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"
# include "macro.h"
# include "utils.h"
# include <sys/time.h>

// ############################### INITIATION ############################### //

int		init(t_data *data, char **argv);
int		init_philos(t_data *data);
int		init_mutexes(t_data *data);

void	*routine(void *arg);
void	monitoring(void *arg);

void	cleanup_total(t_data *data);
void	cleanup_mutexes(t_data *data);
void	cleanup_philos(t_data *data);
int		cleanup_forks_mutexes(t_data *data);

#endif

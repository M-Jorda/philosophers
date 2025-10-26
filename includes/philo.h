/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:47:40 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/28 17:35:11 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"
# include "macro.h"
# include <sys/time.h>

// ############################### INITIATION ############################### //

int		init(t_data *data, char **argv);
int		init_philos(t_data *data);
int		init_mutexes(t_data *data);

// ################################## CORE ################################## //

void	*routine(void *arg);
void	*monitoring(void *arg);
int		take_forks(t_philo *philo);
int		release_forks(t_philo *philo);
bool	isfinish(t_data *data);

// ################################# CLEANUP ################################ //

void	cleanup_total(t_data *data);
void	cleanup_mutexes(t_data *data);
void	cleanup_philos(t_data *data);
int		cleanup_forks_mutexes(t_data *data);

// ################################## DEBUG ################################# //

void	debug(char *mess, int num);
void	debug_data(t_data *data);
void	debug_philos(t_data *data);

// ################################## PRINT ################################# //

int		print_death(t_philo *philo);
int		print_action(t_philo *philo, char *action);

// ################################# UTILS ################################# //

int		ft_atoi(const char *str);
long	calculate_msec(void);
long	get_elapsed_time(t_data *data);
int		printerr(char *mess, int err);
int		check_simulation_end(t_data *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:55:59 by jjorda            #+#    #+#             */
/*   Updated: 2025/10/29 12:33:53 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "struct_bonus.h"
# include "macro.h"

// ############################### INITIATION ############################### //

int		init_b(t_data_b *data, char **argv);
int		init_philos_b(t_data_b *data);
int		init_semaphores_b(t_data_b *data);

// ################################## CORE ################################## //

void	routine_b(t_philo_b *philo);
void	*monitoring_b(void *arg);
void	take_forks_b(t_philo_b *philo);
void	release_forks_b(t_philo_b *philo);
void	monitor_process(t_data_b *data);

// ################################## CLEAN ################################# //

int		cleanup_b(t_data_b *data, int err);
void	kill_philos(t_data_b *data, int index);
void	cleanup_child_b(t_data_b *data);

// ################################## PRINT ################################# //

int		print_action_b(t_philo_b *philo, char *action);
void	print_death_b(t_philo_b *philo);

// ################################## UTILS ################################# //

int		ft_atoi(const char *str);
long	calculate_msec(void);
long	get_elapsed_time(t_data_b *data);
void	ft_wait(long duration_ms, t_data_b *data);
int		printerr(char *mess, int err);

#endif

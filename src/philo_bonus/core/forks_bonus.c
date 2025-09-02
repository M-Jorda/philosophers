/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:28:46 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/28 16:16:23 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	release_forks_b(t_philo_b *philo)
{
	sem_post(philo->data->forks_sem);
	sem_post(philo->data->forks_sem);
}

void	take_forks_b(t_philo_b *philo)
{
	sem_wait(philo->data->forks_sem);
	print_action_b(philo, FORK);
	sem_wait(philo->data->forks_sem);
	print_action_b(philo, FORK);
}

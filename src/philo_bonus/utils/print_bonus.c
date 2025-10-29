/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:26:44 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/28 16:29:48 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print_action_b(t_philo_b *philo, char *action)
{
	if (!philo || !action)
		return (-1);
	sem_wait(philo->data->print_sem);
	printf("%ld %d %s\n", get_elapsed_time(philo->data), philo->id, action);
	sem_post(philo->data->print_sem);
	return (0);
}

void	print_death_b(t_philo_b *philo)
{
	if (!philo)
		return ;
	sem_wait(philo->data->print_sem);
	printf("%ld %d %s\n", get_elapsed_time(philo->data), philo->id, DIED);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:43:45 by jjorda            #+#    #+#             */
/*   Updated: 2025/08/17 10:14:36 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_atoi(const char *str);
long	calculate_msec(void);
long	get_elapsed_time(t_data *data);

int		printerr(char *mess, int err);

#endif
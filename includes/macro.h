/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:58:36 by jjorda            #+#    #+#             */
/*   Updated: 2025/10/29 14:55:18 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# define NOT_ENOUGHT_ARGS	"You need to put at least 4 arguments.\n"
# define TOO_MUCH_ARGS		"You can't put more than 5 arguments.\n"
# define ZERO_PHILO			"THe number of philosophers must be a positive\n"

# define WRONG_PHILO		"The number of philosopher must be a positive\
 number.\n"
# define WRONG_TTD			"The time to die must be a positive number.\n"
# define WRONG_TTE			"The time to eat must be a positive number.\n"
# define WRONG_TTS			"The time to sleep must be a positive number.\n"
# define WRONG_MEAL_COUNT	"The count they must eat is wrong.\n"

# define DIED				"died"
# define EAT				"is eating"
# define SLEEP				"is sleeping"
# define THINK				"is thinking"
# define FORK				"has taken a fork"

/* ********************* BONUS SPECIFIC ********************* */

# define SEM_FAILED_MSG     "Failed to create semaphore.\n"
# define FORK_FAILED_MSG    "Failed to fork process.\n"

# define EXIT_SUCCESS_FED   0
# define EXIT_DEATH         1
# define EXIT_ERROR         2

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:03:24 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/09 15:08:43 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	end_prog(t_data *data)
{
	int	end;

	pthread_mutex_lock(&data->stop_lock);
	end = data->stop_prog;
	pthread_mutex_unlock(&data->stop_lock);
	if (end)
		return (1);
	return (0);
}

size_t	get_meal_count(t_philo *philo)
{
	size_t	meal_count;

	pthread_mutex_lock(&philo->mcount_lock);
	meal_count = philo->meal_count;
	pthread_mutex_unlock(&philo->mcount_lock);
	return (meal_count);
}

useconds_t	get_last_meal(t_philo *philo)
{
	useconds_t	last_meal;

	pthread_mutex_lock(&philo->lastm_lock);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->lastm_lock);
	return (last_meal);
}

int	get_state(t_philo *philo)
{
	int	state;

	pthread_mutex_lock(&philo->state_lock);
	state = philo->state;
	pthread_mutex_unlock(&philo->state_lock);
	return (state);
}

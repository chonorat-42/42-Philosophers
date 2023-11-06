/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:16:26 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/06 18:05:59 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_handler(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_lock);
	print_action(philo->data, get_time(philo->data->start_time),
		philo->id, FORK);
	pthread_mutex_lock(&philo->next->fork_lock);
	print_action(philo->data, get_time(philo->data->start_time),
		philo->id, FORK);
	philo->state = EATING;
	print_action(philo->data, get_time(philo->data->start_time),
		philo->id, EATING);
	ft_usleep(philo->data->t_eat);
	pthread_mutex_unlock(&philo->fork_lock);
	pthread_mutex_unlock(&philo->next->fork_lock);
	philo->meal_count++;
	philo->last_meal = get_time(philo->last_meal);
	philo->state = SLEEPING;
	print_action(philo->data, get_time(philo->data->start_time),
		philo->id, SLEEPING);
	ft_usleep(philo->data->t_sleep);

	philo->alive = 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:16:26 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/07 22:36:54 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleep_after_meal(t_philo *philo)
{
	useconds_t	time;

	time = get_time(philo->data->start_time);
	pthread_mutex_unlock(&philo->fork_lock);
	pthread_mutex_unlock(&philo->next->fork_lock);
	philo->meal_count++;
	if (philo->data->stop_prog)
		return ;
	philo->state = SLEEPING;
	print_action(philo->data, time, philo->id, SLEEPING);
	ft_usleep(philo->data->t_sleep);
}

static int	get_fork(t_philo *philo)
{
	if (philo->data->stop_prog)
		return (0);
	pthread_mutex_lock(&philo->fork_lock);
	if (philo->data->stop_prog)
		return (pthread_mutex_unlock(&philo->fork_lock), 0);
	print_action(philo->data, get_time(philo->data->start_time),
		philo->id, FORK);
	if (philo->data->philo_nbr < 2)
		return (pthread_mutex_unlock(&philo->fork_lock), 0);
	pthread_mutex_lock(&philo->next->fork_lock);
	if (philo->data->stop_prog)
		return (0);
	print_action(philo->data, get_time(philo->data->start_time),
		philo->id, FORK);
	return (1);
}

void	eat_handler(t_philo *philo)
{
	useconds_t	time;

	if (!get_fork(philo))
		return ;
	time = get_time(philo->data->start_time);
	philo->state = EATING;
	print_action(philo->data, time,
		philo->id, EATING);
	ft_usleep(philo->data->t_eat);
	philo->last_meal = get_time(philo->data->start_time);
	sleep_after_meal(philo);
}
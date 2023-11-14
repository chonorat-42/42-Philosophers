/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:16:26 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/14 16:34:37 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleep_after_meal(t_philo *philo)
{
	useconds_t	time;

	time = get_time(philo->data->start_time);
	pthread_mutex_unlock(&philo->fork_lock);
	pthread_mutex_unlock(&philo->next->fork_lock);
	pthread_mutex_lock(&philo->mcount_lock);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->mcount_lock);
	if (end_prog(philo->data))
		return ;
	update_state(philo, SLEEPING);
	print_action(philo->data, time, philo->id, SLEEPING);
	ft_usleep(philo->data->t_sleep);
}

static int	get_fork(t_philo *philo)
{
	if (end_prog(philo->data))
		return (0);
	pthread_mutex_lock(&philo->fork_lock);
	if (end_prog(philo->data))
		return (pthread_mutex_unlock(&philo->fork_lock), 0);
	print_action(philo->data, get_time(philo->data->start_time),
		philo->id, FORK);
	if (philo->data->philo_nbr < 2)
		return (pthread_mutex_unlock(&philo->fork_lock), 0);
	pthread_mutex_lock(&philo->next->fork_lock);
	if (end_prog(philo->data))
		return (pthread_mutex_unlock(&philo->fork_lock),
			pthread_mutex_unlock(&philo->next->fork_lock), 0);
	print_action(philo->data, get_time(philo->data->start_time),
		philo->id, FORK);
	return (1);
}

void	eat_handler(t_philo *philo)
{
	useconds_t	time;

	if (!get_fork(philo))
		return ;
	philo->last_meal = get_time(philo->data->start_time);
	if (end_prog(philo->data))
	{
		pthread_mutex_unlock(&philo->fork_lock);
		pthread_mutex_unlock(&philo->next->fork_lock);
		return ;
	}
	update_state(philo, EATING);
	time = get_time(philo->data->start_time);
	print_action(philo->data, time,
		philo->id, EATING);
	pthread_mutex_lock(&philo->lastm_lock);
	pthread_mutex_unlock(&philo->lastm_lock);
	ft_usleep(philo->data->t_eat);
	sleep_after_meal(philo);
}

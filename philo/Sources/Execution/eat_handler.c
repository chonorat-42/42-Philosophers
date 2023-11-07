/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:16:26 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/08 00:13:38 by chonorat         ###   ########.fr       */
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

static void	sleep_after_meal(t_philo *philo)
{
	useconds_t	time;

	time = get_time(philo->data->start_time);
	pthread_mutex_unlock(&philo->fork_lock);
	pthread_mutex_unlock(&philo->next->fork_lock);
	philo->meal_count++;
	if (end_prog(philo->data))
		return ;
	philo->state = SLEEPING;
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
	time = get_time(philo->data->start_time);
	philo->state = EATING;
	print_action(philo->data, time,
		philo->id, EATING);
	ft_usleep(philo->data->t_eat);
	philo->last_meal = get_time(philo->data->start_time);
	sleep_after_meal(philo);
}
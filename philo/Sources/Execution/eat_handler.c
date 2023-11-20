/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:16:26 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/16 12:25:56 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	drop_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_lock);
	philo->fork = 1;
	pthread_mutex_unlock(&philo->fork_lock);
}

static void	sleep_after_meal(t_philo *philo)
{
	drop_fork(philo->next);
	drop_fork(philo);
	if (end_prog(philo->data))
		return ;
	pthread_mutex_lock(&philo->mcount_lock);
	philo->meal_count++;
	pthread_mutex_unlock(&philo->mcount_lock);
	if (end_prog(philo->data))
		return ;
	update_state(philo, SLEEPING);
	print_action(philo->data, philo->id, SLEEPING);
	ft_usleep(philo->data, philo->data->t_sleep);
}

static void	wait_fork(t_philo *philo)
{
	int	wait_fork;

	wait_fork = 0;
	while (!wait_fork)
	{
		pthread_mutex_lock(&philo->fork_lock);
		wait_fork = philo->fork;
		if (wait_fork)
			philo->fork = 0;
		pthread_mutex_unlock(&philo->fork_lock);
		usleep(1);
	}
}

static int	get_fork(t_philo *philo)
{
	if (end_prog(philo->data))
		return (0);
	wait_fork(philo);
	if (end_prog(philo->data))
		return (drop_fork(philo), 0);
	print_action(philo->data, philo->id, FORK);
	if (philo->data->philo_nbr < 2)
		return (drop_fork(philo), 0);
	wait_fork(philo->next);
	if (end_prog(philo->data))
		return (drop_fork(philo), drop_fork(philo->next), 0);
	print_action(philo->data, philo->id, FORK);
	return (1);
}

void	eat_handler(t_philo *philo)
{
	if (!get_fork(philo))
		return ;
	if (end_prog(philo->data))
	{
		drop_fork(philo);
		drop_fork(philo->next);
		return ;
	}
	update_state(philo, EATING);
	print_action(philo->data, philo->id, EATING);
	pthread_mutex_lock(&philo->lastm_lock);
	philo->last_meal = get_time(philo->data->start_time);
	pthread_mutex_unlock(&philo->lastm_lock);
	ft_usleep(philo->data, philo->data->t_eat);
	sleep_after_meal(philo);
}

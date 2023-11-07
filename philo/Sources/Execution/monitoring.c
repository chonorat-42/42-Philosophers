/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:46:08 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/07 15:04:01 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_death(t_data *data, t_philo *philo)
{
	useconds_t	time;

	time = get_time(data->start_time);
	if ((time - philo->last_meal) >= data->t_death && philo->state != EATING)
	{
		pthread_mutex_lock(&data->stop_lock);
		data->stop_prog = 1;
		pthread_mutex_unlock(&data->stop_lock);
		pthread_mutex_lock(&philo->life_lock);
		philo->alive = 0;
		pthread_mutex_unlock(&philo->life_lock);
		print_action(data, time, philo->id, DEATH);
		return (1);
	}
	return (0);
}

static void	*monitoring(void *arg)
{
	t_data	*data;
	t_philo	*philo;
	size_t	index;

	index = 1;
	data = (t_data *)arg;
	philo = data->philo;
	while (!data->stop_prog)
	{
		if (check_death(data, philo))
			continue ;
	}
	return (NULL);
}

int	start_monitoring(t_data *data)
{
	if (pthread_create(&data->monitoring, NULL, monitoring, data))
		return (0);
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:46:08 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/15 12:10:02 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_death(t_data *data, t_philo *philo)
{
	useconds_t	time;

	time = get_time(data->start_time);
	if ((time - get_last_meal(philo)) >= data->t_death
		&& get_state(philo) != EATING && !end_prog(data))
	{
		pthread_mutex_lock(&data->stop_lock);
		data->stop_prog = 1;
		pthread_mutex_unlock(&data->stop_lock);
		print_action(data, philo->id, DEATH);
		return (1);
	}
	return (0);
}

static void	*death_monitoring(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)arg;
	philo = data->philo;
	while (!end_prog(data))
	{
		if (check_death(data, philo))
			return (NULL);
		philo = philo->next;
		usleep(100);
	}
	return (NULL);
}

static int	check_meal(t_data *data, t_philo *philo, size_t *has_eaten)
{
	size_t	index;

	index = 1;
	while (index <= data->philo_nbr)
	{
		if (get_meal_count(philo) >= data->min_meal)
			(*has_eaten)++;
		if (*has_eaten == data->philo_nbr)
		{
			pthread_mutex_lock(&data->stop_lock);
			data->stop_prog = 1;
			pthread_mutex_unlock(&data->stop_lock);
			return (1);
		}
		philo = philo->next;
		index++;
		usleep(100);
	}
	return (0);
}

static void	*meal_monitoring(void *arg)
{
	t_data	*data;
	t_philo	*philo;
	size_t	has_eaten;

	data = (t_data *)arg;
	philo = data->philo;
	while (!end_prog(data) && data->min_meal > 0)
	{
		has_eaten = 0;
		if (check_meal(data, philo, &has_eaten))
			break ;
	}
	return (NULL);
}

int	start_monitoring(t_data *data)
{
	if (pthread_create(&data->death_monitoring, NULL, death_monitoring, data))
		return (0);
	if (pthread_create(&data->meal_monitoring, NULL, meal_monitoring, data))
		return (0);
	return (1);
}

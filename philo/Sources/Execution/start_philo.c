/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:53:50 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/04 17:24:18 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
static void	*is_thinking(void *philo)
{
	return (philo);
}

static void	test_threads(t_data *data)
{
	t_philo	*temp;
	size_t	index[2];

	temp = data->philo;
	index[0] = 1;
	index[1] = 0;
	while (index[1] < 1)
	{
		while (index[0] <= data->philo_nbr)
		{
			pthread_create(&temp->thread, NULL, is_thinking, temp);
			print_action(data, get_time(data->start_time), temp->id, THINKING);
			pthread_join(temp->thread, NULL);
			temp = temp->next;
			index[0]++;
		}
		index[1]++;
	}
}*/

// int	launch_threads(t_data *data)
// {
// 	t_philo	*temp;
// 	size_t	index;

// 	temp = data->philo;
// 	index = 1;
// 	while (index <= data->philo_nbr)
// 	{
// 		if (pthread_create(&temp->thread, NULL, p_thread_t, &temp));
// 			return (0);
// 		temp = temp->next;
// 		index++;
// 	}
// }

static void	add_meal(t_data *data)
{
	pthread_mutex_lock(&data->eat_lock);
	data->eat_count++;
	pthread_mutex_unlock(&data->eat_lock);
}

static void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->group % 2)
	{
		pthread_mutex_lock(&philo->fork_lock);
		pthread_mutex_lock(&philo->next->fork_lock);
		print_action(philo->data, get_time(philo->data->start_time), philo->id, EATING);
		add_meal(philo->data);
		usleep(philo->data->t_eat * 1000);
		pthread_mutex_unlock(&philo->next->fork_lock);
		pthread_mutex_unlock(&philo->fork_lock);
		print_action(philo->data, get_time(philo->data->start_time), philo->id, SLEEPING);
		usleep(philo->data->t_sleep * 1000);
	}
	else
		print_action(philo->data, get_time(philo->data->start_time),
			philo->id, THINKING);
	philo->group++;
	return (NULL);
}

static int	philo_handler(t_data *data, t_philo *philo)
{
	size_t	index;

	index = 1;
	while (index <= data->philo_nbr)
	{
		if (pthread_create(&philo->thread, NULL, philo_thread, philo))
			return (0);
		pthread_join(philo->thread, NULL);
		philo = philo->next;
		index++;
	}
	pthread_mutex_lock(&data->death_lock);
	data->death++;
	pthread_mutex_unlock(&data->death_lock);
	return (1);
}

int	start_philo(t_data *data)
{
	t_philo	*philo;

	philo = data->philo;
	while (data->death != 3)
	{
		philo_handler(data, philo);
	}
	return (1);
}
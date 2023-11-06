/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:46:45 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/06 17:55:35 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_data *data, t_philo **philo, int id)
{
	(*philo)->id = id;
	(*philo)->alive = 1;
	(*philo)->state = 0;
	(*philo)->meal_count = 0;
	(*philo)->last_meal = 0;
	(*philo)->data = data;
	(*philo)->prev = NULL;
	(*philo)->next = NULL;
	if (data->philo_nbr % 2 && (*philo)->id == data->philo_nbr)
		(*philo)->group = 0;
	else
		(*philo)->group = id % 2;
}

int	create_table(t_data *data)
{
	size_t	index;
	t_philo	*temp;
	t_philo	*prev;

	index = 1;
	data->philo = malloc(sizeof(t_philo));
	if (!data->philo)
		return (show_error(MALLOC, 0), 0);
	init_philo(data, &data->philo, index++);
	prev = data->philo;
	temp = data->philo->next;
	while (index <= data->philo_nbr)
	{
		temp = malloc(sizeof(t_philo));
		if (!temp)
			return (show_error(MALLOC, 0), free_data(data), 0);
		init_philo(data, &temp, index++);
		temp->prev = prev;
		prev->next = temp;
		prev = temp;
		temp = temp->next;
	}
	prev->next = data->philo;
	data->philo->prev = prev;
	return (1);
}

void	init_mutex(t_data *data)
{
	t_philo	*philo;
	size_t	index;

	pthread_mutex_init(&data->print, NULL);
	philo = data->philo;
	index = 1;
	while (philo && index <= data->philo_nbr)
	{
		pthread_mutex_init(&philo->fork_lock, NULL);
		pthread_mutex_init(&philo->meal_lock, NULL);
		pthread_mutex_init(&philo->life_lock, NULL);
		pthread_mutex_init(&philo->mcount_lock, NULL);
		philo = philo->next;
		index++;
	}
}

int	init_data(t_data *data)
{
	data->start_time = init_time();
	if (!data->start_time)
		return (0);
	data->philo_nbr = 0;
	data->t_death = 0;
	data->t_eat = 0;
	data->t_sleep = 0;
	data->philo = NULL;
	return (1);
}
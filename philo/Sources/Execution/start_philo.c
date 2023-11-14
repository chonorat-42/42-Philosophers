/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:53:50 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/14 16:37:54 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_state(t_philo *philo, int state)
{
	pthread_mutex_lock(&philo->state_lock);
	philo->state = state;
	pthread_mutex_unlock(&philo->state_lock);
}

static void	*philo_handler(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	print_action(philo->data, get_time(philo->data->start_time),
		philo->id, THINKING);
	update_state(philo, THINKING);
	if (!philo->group)
		ft_usleep(philo->data->t_eat - 10);
	while (!end_prog(philo->data))
	{
		if (philo->group++)
		{
			eat_handler(philo);
			if (philo->data->philo_nbr < 2)
				break ;
			if (end_prog(philo->data))
				break ;
			update_state(philo, THINKING);
			print_action(philo->data, get_time(philo->data->start_time),
				philo->id, THINKING);
		}
	}
	return (NULL);
}

int	start_philo(t_data *data)
{
	t_philo	*philo;
	size_t	index;

	index = 1;
	philo = data->philo;
	while (philo && index <= data->philo_nbr)
	{
		if (pthread_create(&philo->thread, NULL, philo_handler, philo))
			return (0);
		usleep(1);
		philo = philo->next;
		index++;
	}
	return (1);
}

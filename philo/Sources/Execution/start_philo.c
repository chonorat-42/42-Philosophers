/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:53:50 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/07 17:56:41 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_handler(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	print_action(philo->data, get_time(philo->data->start_time),
		philo->id, THINKING);
	philo->state = THINKING;
	if (!philo->group)
		ft_usleep(philo->data->t_eat - 10);
	while (philo->alive && !philo->data->stop_prog)
	{
		if (philo->group++)
		{
			eat_handler(philo);
			if (philo->data->stop_prog)
				break ;
			print_action(philo->data, get_time(philo->data->start_time),
			philo->id, THINKING);
			philo->state = THINKING;
		}
		if (philo->data->stop_prog)
				break ;
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
		philo = philo->next;
		index++;
	}
	return (1);
}

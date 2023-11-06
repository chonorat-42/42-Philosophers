/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:53:50 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/06 17:52:52 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo->group)
		ft_usleep(philo->data->t_eat - 10);
	while (philo->alive)
	{
		if (philo->group)
			eat_handler(philo);
		philo->group++;
	}
	return (NULL);
}

static void	join_philo(t_data *data)
{
	t_philo	*philo;
	size_t	index;

	index = 1;
	philo = data->philo;
	while (index <= data->philo_nbr)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
		index++;
	}
}

static int	start_philo(t_data *data)
{
	t_philo	*philo;
	size_t	index;

	index = 1;
	philo = data->philo;
	while (philo && index <= data->philo_nbr)
	{
		if (pthread_create(&philo->thread, NULL, &philo_routine, philo))
			return (0);
		philo = philo->next;
		index++;
	}
	join_philo(data);
	return (1);
}

int	philo_handler(t_data *data)
{
	if (!start_philo(data))
		return (0);
	return (1);
}
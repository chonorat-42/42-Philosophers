/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:16:35 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/09 15:00:17 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_philo(t_philo **philo, size_t philo_nbr)
{
	t_philo	*temp;
	t_philo	*next;
	size_t	index;

	index = 0;
	temp = *philo;
	while (temp && index < philo_nbr)
	{
		next = temp->next;
		pthread_mutex_destroy(&temp->fork_lock);
		pthread_mutex_destroy(&temp->state_lock);
		pthread_mutex_destroy(&temp->mcount_lock);
		pthread_mutex_destroy(&temp->lastm_lock);
		free(temp);
		temp = next;
		index++;
	}
	*philo = NULL;
}

void	free_data(t_data *data)
{
	if (data->philo)
		free_philo(&data->philo, data->philo_nbr);
	pthread_mutex_destroy(&data->print);
}

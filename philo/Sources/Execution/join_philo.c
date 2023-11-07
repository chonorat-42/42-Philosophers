/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:58:32 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/07 21:34:26 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_philo(t_data *data)
{
	t_philo	*philo;
	size_t	index;

	index = 1;
	pthread_join(data->death_monitoring, NULL);
	pthread_join(data->meal_monitoring, NULL);
	philo = data->philo;
	while (index <= data->philo_nbr)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
		index++;
	}
}
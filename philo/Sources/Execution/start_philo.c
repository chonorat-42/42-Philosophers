/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:53:50 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/01 17:24:06 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
}

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

int	start_philo(t_data *data)
{
	test_threads(data);
	return (1);
}
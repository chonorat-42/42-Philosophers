/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:09:44 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/14 17:00:39 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_data *data, size_t id, int action)
{
	pthread_mutex_lock(&data->print);
	if (!end_prog(data))
	{
		if (action == THINKING)
			printf("%u %ld is thinking\n", get_time(data->start_time), id);
		else if (action == EATING)
			printf("%u %ld is eating\n", get_time(data->start_time), id);
		else if (action == SLEEPING)
			printf("%u %ld is sleeping\n", get_time(data->start_time), id);
		else if (action == FORK)
			printf("%u %ld has taken a fork\n", get_time(data->start_time), id);
	}
	if (action == DEATH)
		printf("%u %ld died\n", get_time(data->start_time), id);
	pthread_mutex_unlock(&data->print);
}

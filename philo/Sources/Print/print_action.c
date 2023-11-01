/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:09:44 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/01 17:00:44 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_data *data, useconds_t time, int id, int action)
{
	pthread_mutex_lock(&data->print);
	if (action == THINKING)
		printf("%u %d is thinking\n", time, id);
	else if (action == EATING)
		printf("%u %d is eating\n", time, id);
	else if (action == SLEEPING)
		printf("%u %d is sleeping\n", time, id);
	else if (action == FORK)
		printf("%u %d has taken a fork\n", time, id);
	pthread_mutex_unlock(&data->print);
}
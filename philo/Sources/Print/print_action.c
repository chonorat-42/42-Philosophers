/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:09:44 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/09 13:47:36 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_data *data, useconds_t time, size_t id, int action)
{
	pthread_mutex_lock(&data->print);
	if (!end_prog(data))
	{
		if (action == THINKING)
			printf("%u %ld is thinking\n", time, id);
		else if (action == EATING)
			printf("%u %ld is eating\n", time, id);
		else if (action == SLEEPING)
			printf("%u %ld is sleeping\n", time, id);
		else if (action == FORK)
			printf("%u %ld has taken a fork\n", time, id);
	}
	if (action == DEATH)
		printf("%u %ld died\n", time, id);
	pthread_mutex_unlock(&data->print);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:31:49 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/07 22:22:15 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

useconds_t	init_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (show_error(TIME, 0), 0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

useconds_t	get_time(useconds_t start)
{
	struct timeval	time;
	useconds_t		actual_time;

	if (gettimeofday(&time, NULL) == -1)
		return (show_error(TIME, 0), 0);
	actual_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (actual_time - start);
}
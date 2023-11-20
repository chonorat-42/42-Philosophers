/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:57:32 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/16 12:45:02 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(t_data *data, useconds_t sleep)
{
	useconds_t	init;

	init = init_time();
	while (((init_time() - init) < sleep) && !end_prog(data))
		usleep(500);
}

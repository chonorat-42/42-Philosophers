/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:24:17 by chonorat          #+#    #+#             */
/*   Updated: 2023/10/28 14:39:40 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_data(t_data *data)
{
	data->philo_nbr = 0;
	data->t_death = 0;
	data->t_eat = 0;
	data->t_sleep = 0;
	data->nbr_to_eat = 0;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	init_data(&data);
	if (argc == 5 || argc == 6)
	{
		if (!get_arg(&data, argc, argv))
			return (EXIT_FAILURE);
	}
	else
		return (show_error(ARGC, 0), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:24:17 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/07 23:28:32 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (!init_data(&data))
			return (EXIT_FAILURE);
		if (!get_arg(&data, argc, argv))
			return (EXIT_FAILURE);
		if (!create_table(&data))
			return (EXIT_FAILURE);
		init_mutex(&data);
		if (!start_philo(&data))
			return (EXIT_FAILURE);
		if (!start_monitoring(&data))
			return (EXIT_FAILURE);
		join_philo(&data);
		free_data(&data);
	}
	else
		return (show_error(ARGC, 0), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
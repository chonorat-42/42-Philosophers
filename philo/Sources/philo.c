/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:24:17 by chonorat          #+#    #+#             */
/*   Updated: 2023/10/29 15:47:29 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
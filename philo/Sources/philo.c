/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:24:17 by chonorat          #+#    #+#             */
/*   Updated: 2023/10/29 17:08:06 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_table(t_philo *philo, size_t nbr)
{
	size_t	index;

	index = 0;
	while (index < nbr)
	{
		printf("philo_id: (%zu)\n", philo->id);
		philo = philo->next;
		index++;
	}
	printf("--------------------\n");
	while (nbr > 0)
	{
		philo = philo->prev;
		printf("philo_id: (%zu)\n", philo->id);
		nbr--;
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	init_data(&data);
	if (argc == 5 || argc == 6)
	{
		if (!get_arg(&data, argc, argv))
			return (EXIT_FAILURE);
		if (!create_table(&data))
			return (EXIT_FAILURE);
		print_table(data.philo, data.philo_nbr);
		free_data(&data);
	}
	else
		return (show_error(ARGC, 0), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
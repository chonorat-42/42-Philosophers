/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:24:17 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/06 16:49:31 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	print_table(t_philo *philo, size_t nbr, useconds_t time)
// {
// 	size_t	index;

// 	index = 0;
// 	printf("<%ld><%ld>\n\n", init_time(), time);
// 	while (index < nbr)
// 	{
// 		printf("philo_id: (%zu)[%d]\n", philo->id, philo->group);
// 		philo = philo->next;
// 		index++;
// 	}
// 	printf("--------------------\n");
// 	while (nbr > 0)
// 	{
// 		philo = philo->prev;
// 		printf("philo_id: (%zu)[%d]\n", philo->id, philo->group);
// 		nbr--;
// 	}
// }

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
		// print_table(data.philo, data.philo_nbr, data.start_time);
		philo_handler(&data);
		free_data(&data);
	}
	else
		return (show_error(ARGC, 0), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:40:45 by chonorat          #+#    #+#             */
/*   Updated: 2023/10/28 23:54:02 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	only_digit(char *arg, int *arg_nbr)
{
	int	index;

	index = 0;
	if (arg[index] == '-' || arg[index] == '+')
		index++;
	while (arg[index])
	{
		if (arg[index] < '0' || arg[index] > '9')
			return (0);
		index++;
	}
	*arg_nbr = ft_atoi(arg);
	return (1);
}

static int	store_data(t_data *data, int index, int arg_nbr)
{
	if (index == 1)
	{
		if (arg_nbr < 1 || arg_nbr > 200)
			return (show_error(WRONG_NBR, 1), 0);
		data->philo_nbr = arg_nbr;
	}
	else if (index < 5)
	{
		if (arg_nbr < 60)
			return (show_error(WRONG_NBR, 2), 0);
		if (index == 2)
			data->t_death = arg_nbr;
		else if (index == 3)
			data->t_eat = arg_nbr;
		else if (index == 4)
			data->t_sleep = arg_nbr;
	}
	else if (index == 5)
	{
		if (arg_nbr < 0)
			return (show_error(WRONG_NBR, 3), 0);
		data->nbr_to_eat = arg_nbr;
	}
	return (1);
}

int	get_arg(t_data *data, int argc, char **argv)
{
	int	index;
	int	arg_nbr;

	index = 1;
	arg_nbr = 0;
	while (index < argc)
	{
		if (!only_digit(argv[index], &arg_nbr))
			return (show_error(WRONG_ARG, 0), 0);
		if (!store_data(data, index++, arg_nbr))
			return (0);
	}
	return (1);
}
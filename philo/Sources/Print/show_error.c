/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:24:59 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/09 15:01:53 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	arg_error(void)
{
	ft_putstr_fd("usage: ./philo ", 2);
	ft_putstr_fd("number_of_philosopher ", 2);
	ft_putstr_fd("time_to_die ", 2);
	ft_putstr_fd("time_to_eat ", 2);
	ft_putstr_fd("time_to_sleep ", 2);
	ft_putstr_fd("[number_of_times_each_philosopher_must_eat]\n", 2);
}

static void	nbr_error(int error)
{
	if (error == 1)
		ft_putstr_fd("Philo number must be between 1 and 200.\n", 2);
	else if (error == 2)
		ft_putstr_fd("Time cannot be set under 60ms.\n", 2);
	else if (error == 3)
		ft_putstr_fd("Value must be over 0.\n", 2);
}

void	show_error(int type, int error)
{
	ft_putstr_fd("Error\n", 2);
	if (type == ARGC)
		arg_error();
	else if (type == WRONG_ARG)
		ft_putstr_fd("Wrong argument. Insert only numbers.\n", 2);
	else if (type == WRONG_NBR)
		nbr_error(error);
	else if (type == MALLOC)
		ft_putstr_fd("Malloc error.\n", 2);
	else if (type == TIME)
		ft_putstr_fd("Cannot retrieve current time.\n", 2);
}

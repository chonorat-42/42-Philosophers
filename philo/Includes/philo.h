/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:22:10 by chonorat          #+#    #+#             */
/*   Updated: 2023/10/28 14:39:33 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//ERROR
# define ARGC 1
# define WRONG_ARG 2
# define WRONG_NBR 3

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_data
{
	int	philo_nbr;
	int	t_death;
	int	t_eat;
	int	t_sleep;
	int	nbr_to_eat;
}				t_data;

int		get_arg(t_data *data, int argc, char **argv);

void	show_error(int type, int error);

int		ft_atoi(const char *str);
int		ft_putstr_fd(char *s, int fd);

#endif
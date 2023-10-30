/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:22:10 by chonorat          #+#    #+#             */
/*   Updated: 2023/10/30 12:16:25 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//ERROR
# define ARGC 1
# define WRONG_ARG 2
# define WRONG_NBR 3
# define MALLOC 4

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_philo
{
	size_t			id;
	int				group;
	int				fork;
	pthread_mutex_t	fork_lock;
	struct s_philo	*prev;
	struct s_philo	*next;
}					t_philo;

typedef struct	s_data
{
	size_t			philo_nbr;
	size_t			t_death;
	size_t			t_eat;
	size_t			t_sleep;
	size_t			nbr_to_eat;
	t_philo			*philo;
	pthread_mutex_t	print;
}				t_data;

void	init_data(t_data *data);
int		create_table(t_data *data);

int		get_arg(t_data *data, int argc, char **argv);

void	show_error(int type, int error);

int		ft_atoi(const char *str);
int		ft_putstr_fd(char *s, int fd);

void	free_data(t_data *data);

#endif
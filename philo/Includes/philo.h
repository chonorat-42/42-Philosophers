/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:22:10 by chonorat          #+#    #+#             */
/*   Updated: 2023/11/06 17:24:22 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//ERROR
# define ARGC 1
# define WRONG_ARG 2
# define WRONG_NBR 3
# define MALLOC 4
# define TIME 5

//ACTION
# define THINKING 1
# define EATING 2
# define SLEEPING 3
# define FORK 4

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_philo
{
	pthread_t		thread;
	size_t			id;
	int				group;
	int				state;
	int				alive;
	pthread_mutex_t	life_lock;
	pthread_mutex_t	fork_lock;
	size_t			meal_count;
	pthread_mutex_t	mcount_lock;
	useconds_t		last_meal;
	pthread_mutex_t	meal_lock;
	struct s_data	*data;
	struct s_philo	*prev;
	struct s_philo	*next;
}					t_philo;

typedef struct	s_data
{
	useconds_t		start_time;
	size_t			philo_nbr;
	size_t			t_death;
	size_t			t_eat;
	size_t			t_sleep;
	size_t			min_meal;
	t_philo			*philo;
	pthread_mutex_t	print;
}				t_data;

int			init_data(t_data *data);
useconds_t	init_time(void);
void		init_mutex(t_data *data);
int			create_table(t_data *data);

int			get_arg(t_data *data, int argc, char **argv);
useconds_t	get_time(useconds_t start);

int			philo_handler(t_data *data);
int			launch_threads(t_data *data);

void		print_action(t_data *data, useconds_t time, size_t id, int action);
void		eat_handler(t_philo *philo);

void		show_error(int type, int error);

int			ft_atoi(const char *str);
int			ft_putstr_fd(char *s, int fd);
void		ft_usleep(useconds_t sleep);

void		free_data(t_data *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:11:42 by tgeorge           #+#    #+#             */
/*   Updated: 2023/08/28 13:04:22 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				nb_philo;
	int				tdie;
	int				teat;
	int				tsleep;
	int				nb_meal;
	int				current_nb_meal;
	long long		tstart;
	long			t_current;
	int				num_philo;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*lf;
	pthread_mutex_t	*rf;
	struct s_data	*phi_data;
}		t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				tdie;
	int				teat;
	int				tsleep;
	int				nb_meal;
	int				dead_philo;
	long long		tstart;
	long			t_current;
	t_philo			*philos;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	write;
	pthread_mutex_t	dead;
	pthread_mutex_t	meal;
}		t_data;

int			init_values(t_data *data, int ac, char **av);
int			init_mutex(t_data *data);
void		init_philo(t_data *data);
int			init_thread(t_data *data);

long		get_start_time(void);
long long	get_current_time(t_philo *phi);
int			free_all(t_data *data);
int			ft_atoi(char *str);
void		message(t_philo *phi, char *str);

void		*thread_routine(void *philosoph);
void		thinking(t_philo *phi);
int			check_death(t_data *data);
void		lock_forks(t_philo *phi);
void		unlock_forks(t_philo *phi);
void		ft_usleep(int i, t_data *data);

void		solo(t_data *data);
int			check_die(t_data *data);
int			norm(t_data *data, int i);
void		ft_death(t_data *data, int i);
int			check_all_phi_meal(t_data *data);
int			check_full_meal(t_philo *phi);

#endif
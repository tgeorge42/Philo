/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:49:08 by tgeorge           #+#    #+#             */
/*   Updated: 2024/04/24 18:07:27 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_death(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->dead);
	i = data->dead_philo;
	pthread_mutex_unlock(&data->dead);
	return (i);
}

void	thinking(t_philo *phi)
{
	if (phi->nb_philo % 2)
	{
		ft_usleep((phi->teat - phi->tsleep + 5), phi->phi_data);
	}
}

void	*thread_routine(void *philosoph)
{
	t_philo	*phi;

	phi = (t_philo *)philosoph;
	while (!check_death(phi->phi_data) && !check_full_meal(phi))
	{
		lock_forks(phi);
		message(phi, "has taken a fork");
		message(phi, "has taken a fork");
		message(phi, "is eating");
		pthread_mutex_lock(&phi->phi_data->meal);
		phi->last_meal = get_current_time(phi);
		phi->current_nb_meal++;
		pthread_mutex_unlock(&phi->phi_data->meal);
		ft_usleep(phi->teat, phi->phi_data);
		unlock_forks(phi);
		message(phi, "is sleeping");
		ft_usleep(phi->tsleep, phi->phi_data);
		message(phi, "is thinking");
		thinking(phi);
	}
	return (NULL);
}

void	lock_forks(t_philo *phi)
{
	if (phi->num_philo % 2)
	{
		pthread_mutex_lock(phi->lf);
		pthread_mutex_lock(phi->rf);
	}
	else
	{
		pthread_mutex_lock(phi->rf);
		pthread_mutex_lock(phi->lf);
	}
}

void	unlock_forks(t_philo *phi)
{
	if (phi->num_philo % 2)
	{
		pthread_mutex_unlock(phi->rf);
		pthread_mutex_unlock(phi->lf);
	}
	else
	{
		pthread_mutex_unlock(phi->lf);
		pthread_mutex_unlock(phi->rf);
	}
}

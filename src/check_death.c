/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:23:23 by tgeorge           #+#    #+#             */
/*   Updated: 2024/04/24 18:07:27 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_die(t_data *data)
{
	int	i;
	int	full_meal;

	i = 0;
	full_meal = 0;
	while (!check_death(data))
	{
		while (i < data->nb_philo)
		{
			if (!check_full_meal(&data->philos[i]))
			{
				if (norm(data, i))
				{
					ft_death(data, i);
					break ;
				}
			}
			i++;
		}
		i = 0;
		if (check_all_phi_meal(data))
			return (1);
	}
	return (1);
}

int	norm(t_data *data, int i)
{
	int	k;

	k = 0;
	pthread_mutex_lock(&data->meal);
	if (get_current_time(&data->philos[i])
		- data->philos[i].last_meal > data->philos[i].tdie)
		k = 1;
	else
		k = 0;
	pthread_mutex_unlock(&data->meal);
	return (k);
}

void	ft_death(t_data *data, int i)
{
	pthread_mutex_lock(&data->dead);
	data->dead_philo = 1;
	pthread_mutex_unlock(&data->dead);
	pthread_mutex_lock(&(data->write));
	printf("%lld %d died\n", get_current_time(&data->philos[i]),
		data->philos[i].num_philo);
	pthread_mutex_unlock(&(data->write));
}

int	check_all_phi_meal(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (!check_full_meal(&data->philos[i]))
			break ;
		i++;
	}
	if (i == data->nb_philo)
		return (1);
	return (0);
}

int	check_full_meal(t_philo *phi)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&phi->phi_data->meal);
	if (phi->nb_meal == -1)
		i = 0;
	else if (phi->nb_meal > 0 && phi->current_nb_meal < phi->nb_meal)
		i = 0;
	else
	{
		phi->last_meal = 0;
		i = 1;
	}
	pthread_mutex_unlock(&phi->phi_data->meal);
	return (i);
}

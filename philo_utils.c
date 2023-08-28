/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:11:34 by tgeorge           #+#    #+#             */
/*   Updated: 2023/08/28 13:11:43 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(t_philo *phi, char *str)
{
	if (!check_death(phi->phi_data))
	{
		pthread_mutex_lock(&(phi->phi_data->write));
		printf("%lld %d %s\n", get_current_time(phi), phi->num_philo, str);
		pthread_mutex_unlock(&(phi->phi_data->write));
	}
}

int	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->mutex[i]);
		i++;
	}
	if (data->philos)
		free(data->philos);
	if (data->mutex)
		free(data->mutex);
	pthread_mutex_destroy(&(data->write));
	pthread_mutex_destroy(&(data->dead));
	pthread_mutex_destroy(&(data->meal));
	return (0);
}

long	get_start_time(void)
{
	struct timeval	tmp;

	gettimeofday(&tmp, NULL);
	return ((tmp.tv_sec * 1000) + (tmp.tv_usec / 1000));
}

int	ft_atoi(char *str)
{
	int	res;
	int	i;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

long long	get_current_time(t_philo *phi)
{
	struct timeval	tmp;

	gettimeofday(&tmp, NULL);
	return (((tmp.tv_sec * 1000) + (tmp.tv_usec / 1000)) - phi->tstart);
}

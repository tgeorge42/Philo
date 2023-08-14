/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:45:20 by tgeorge           #+#    #+#             */
/*   Updated: 2023/08/14 15:46:24 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_values(t_data *data, int ac, char **av)
{
    data->nb_philo = ft_atoi(av[1]);
    data->tdie = ft_atoi(av[2]);
    data->teat = ft_atoi(av[3]);
    data->tsleep = ft_atoi(av[4]);
    data->philos = NULL;
    data->mutex = NULL;
    if (data->nb_philo < 1 || data->tdie < 1 || data->teat < 1
            || data->tsleep < 1)
        exit(0);
    if (ac == 6)
    {
        data->nb_meal = ft_atoi(av[5]);
        if (data->nb_meal < 1)
            exit(0);
    }
    else
    {
        data->nb_meal = -1;
        return(0);
    }
    return(0);
}

void	link_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo - 1)
	{
		data->philos[i].lf = &data->mutex[i];
		data->philos[i].rf = &data->mutex[i + 1];
		i++;
	}
	data->philos[i].lf = &data->mutex[i];
	data->philos[i].rf = &data->mutex[0];
}

int init_mutex(t_data *data)
{
    int	i;

    i = 0;
    data->philos = malloc(sizeof(t_philo) * data->nb_philo);
    if (!data->philos)
        exit(0);
    data->mutex = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
    if (!data->mutex)
        free_all(data);
    while (i < data->nb_philo)
    {
        if (pthread_mutex_init(&(data->mutex[i]), NULL))
            free_all(data);
        i++;
    }
	if (pthread_mutex_init(&(data->dead), NULL))
		free_all(data);
	if (pthread_mutex_init(&(data->meal), NULL))
        free_all(data);
	if (pthread_mutex_init(&(data->write), NULL))
		free_all(data);
	link_philo(data);
    return (0);
}

void	init_philo(t_data *data)
{
	int	i;
    
	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].num_philo = i + 1;
		data->philos[i].last_meal = 0;
		data->philos[i].nb_meal = 0;
		data->philos[i].phi_data = data;
		data->philos[i].nb_philo = data->nb_philo;
		data->philos[i].tdie = data->tdie;
		data->philos[i].teat = data->teat;
		data->philos[i].tsleep = data->tsleep;
		data->philos[i].nb_meal = data->nb_meal;
		data->philos[i].tstart = data->tstart;
		i++;
	}
}
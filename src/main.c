/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:11:37 by tgeorge           #+#    #+#             */
/*   Updated: 2024/04/24 18:07:27 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&(data->philos[i].thread), NULL, thread_routine,
				&(data->philos[i])))
		{
			free_all(data);
			return (0);
		}
		i += 2;
	}
	i = 1;
	while (i < data->nb_philo)
	{
		if (pthread_create(&(data->philos[i].thread), NULL, thread_routine,
				&(data->philos[i])))
		{
			free_all(data);
			return (0);
		}
		i += 2;
	}
	return (1);
}

void	solo(t_data *data)
{
	printf("0 1 has taken a fork\n");
	usleep(data->tdie * 1000);
	printf("%d 1 died\n", (data->tdie + 1));
}

void	ft_usleep(int i, t_data *data)
{
	int	a;

	a = 0;
	while (a < i && !check_death(data))
	{
		usleep(10000);
		a += 10;
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		data.tstart = get_start_time();
		if (init_values(&data, ac, av) == 0)
			return (0);
		if (init_mutex(&data) == 0)
			return (0);
		init_philo(&data);
		if (init_thread(&data) == 0)
			return (0);
		while (!check_die(&data))
			;
		while (i < data.nb_philo)
		{
			pthread_join(data.philos[i].thread, NULL);
			i++;
		}
	}
	free_all(&data);
}

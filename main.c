/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorge <tgeorge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:11:37 by tgeorge           #+#    #+#             */
/*   Updated: 2023/08/14 15:42:48 by tgeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_data  data;
	int	i;

	i = 0;
    if (ac == 5 || ac == 6)
    {
		data.tstart = get_start_time();
        init_values(&data, ac, av);
		init_mutex(&data);
        init_philo(&data);
    }
}

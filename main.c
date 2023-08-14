#include "philo.h"

int ft_atoi(char *str)
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

void    init_values(t_data *data, char **av, int ac)
{
    data->nb_philo = ft_atoi(av[1]);
    data->tdie = ft_atoi(av[2]);
    data->teat = ft_atoi(av[3]);
    data->tsleep = ft_atoi(av[4]);
    if (data->nb_philo < 1 || data->tdie < 1 || data->teat < 1
            || data->tsleep < 1)
        return ;
    if (ac == 6)
    {
        data->nb_meal = ft_atoi(av[5]);
        if (data->nb_meal < 1)
            return;
    }
    else
        data->nb_meal = -1;
}

int main(int ac, char **av)
{
    t_data  data;

    if (ac == 5 || ac == 6)
    {
        init_values(&data, av, ac);
    }
}

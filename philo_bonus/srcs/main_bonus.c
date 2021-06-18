/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:43:54 by spark             #+#    #+#             */
/*   Updated: 2021/06/18 15:33:02 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int		parse_info(t_info *info, char *av[], int ac)
{
	info->philo_num = ft_atoi(av[1]);
	info->life_time = ft_atoi(av[2]);
	info->eat_time = ft_atoi(av[3]);
	info->sleep_time = ft_atoi(av[4]);
	if (info->philo_num < -1 || info->philo_num > 200 ||\
	info->life_time < 0 || info->life_time > 99999 ||\
	info->eat_time < 0 || info->eat_time > 99999 ||\
	info->sleep_time < 0 || info->sleep_time > 99999)
	{
		show_error("Argment Value is too small or big.");
		return (1);
	}
	if (ac == 6)
		info->bucket_eat_time = ft_atoi(av[5]);
	else
		info->bucket_eat_time = -1;
	return (0);
}

int		main(int ac, char *av[])
{
	int				rt;
	t_info			info;
	t_philosopher	*philo;

	rt = 0;
	if (ac < 5 || ac > 6)
		rt = show_error("Argment Num is Incorrect.");
	else
	{
		if (parse_info(&info, av, ac))
			return (1);
		if (info.bucket_eat_time < 0 || info.eat_time < 0 ||\
			info.sleep_time < 0 || info.life_time < 0 || info.philo_num < 0)
			rt = show_error("Argment Value is Incorrect.");
		init_philo(&info, &philo);
		running_philo(&info, philo);
		clean_up_philo(&info, philo);
	}
	return (rt);
}

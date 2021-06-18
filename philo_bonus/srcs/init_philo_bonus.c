/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:45:59 by spark             #+#    #+#             */
/*   Updated: 2021/06/18 14:25:21 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int		get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	init_philo(t_info *info, t_philosopher **philo)
{
	int		i;
	int		num;

	i = -1;
	num = info->philo_num;
	*philo = malloc(sizeof(t_philosopher) * num);
	while (++i < num)
	{
		(*philo)[i].time_of_recent_meal = 0;
		(*philo)[i].eating_count = 0;
		(*philo)[i].info = info;
		(*philo)[i].action = 0;
		(*philo)[i].pid = 0;
	}
	init_info(info, philo);
}

void	init_info(t_info *info, t_philosopher **philo)
{
	int i;
	int total;

	i = -1;
	total = info->philo_num;
	info->fork = malloc(sizeof(sem_t) * total);
	while (++i < total)
	{
		pthread_mutex_init(&info->fork[i], NULL);
		(*philo)[i].number = i + 1;
	}
	info->starting_time = get_time();
	info->check_anyone_dead = 0;
}

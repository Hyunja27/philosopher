/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:45:59 by spark             #+#    #+#             */
/*   Updated: 2021/06/19 17:10:27 by hyunja           ###   ########.fr       */
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
	info->fork = sem_open("fork", O_CREAT | O_EXCL, 0644, total);
	info->for_not_twisted_msg = sem_open("for_msg", O_CREAT | O_EXCL, 0644, 1);
	info->starting_time = get_time();
	info->check_anyone_dead = 0;
	(void)philo;
}

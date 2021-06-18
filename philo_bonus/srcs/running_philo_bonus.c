/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running_philo_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:33:24 by spark             #+#    #+#             */
/*   Updated: 2021/06/18 16:31:07 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	running_philo(t_info *info, t_philosopher *philo)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	// while (++i < info->philo_num)
	// 	pthread_create(&philo[i].pid, NULL, doing_all, &philo[i]);
	// while (++j < info->philo_num)
	// 	pthread_join(philo[j].pid, NULL);
}

void	*doing_all(void *philosopher)
{
	t_philosopher	*philo;
	int				must_count;
	pthread_t		dead_checker;

	philo = (t_philosopher *)philosopher;
	if (philo->number % 2 == 0)
		usleep(philo->info->sleep_time * 1000);
	must_count = philo->info->bucket_eat_time;
	pthread_create(&dead_checker, NULL, &check_dead, philo);
	while (1)
	{
		if (taking_fork(philo) == SOMEONE_DIED)
			break ;
		if (eating(philo) == SOMEONE_DIED)
			break ;
		if (philo->eating_count == must_count)
			break ;
		if (sleeping(philo) == SOMEONE_DIED)
			break ;
		if (thinking(philo) == SOMEONE_DIED)
			break ;
	}
	pthread_join(dead_checker, NULL);
	return (NULL);
}

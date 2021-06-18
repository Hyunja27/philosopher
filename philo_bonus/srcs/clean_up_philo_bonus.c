/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_philo_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:51:45 by spark             #+#    #+#             */
/*   Updated: 2021/06/18 14:18:04 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clean_up_philo(t_info *info, t_philosopher *philo)
{
	int		i;

	i = -1;
	while (++i < info->philo_num)
		pthread_mutex_destroy(&info->fork[i]);
	pthread_mutex_destroy(&info->for_not_twisted_msg);
	free(info->fork);
	free(philo);
}
